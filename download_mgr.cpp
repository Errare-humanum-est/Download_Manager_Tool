#include "download_mgr.h"
#include "ui_download_mgr.h"


download_mgr::download_mgr(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::download_mgr)
{
    ui->setupUi(this);
    // Setup socket successful
    socket_setup=0;
    // Check if rate adaptation shall be activated
    adaptation_on=0;
    // Number of available qualtiy bitrates
    n_bitrates=0;
    // Number of requested quality bitrates
    req_bitrate=0;

    // Initialize segment counter
    segment_counter=1;

    // Segment size is necessary to know for the system to
    // know when playout started, because algortihms need to be adapted
    segment_size=2;

    // Initialize average bitrate value to 0
    average=0;
    integration_limits=ui->int_limits->value();
    buffer_size=0;

    playout_started=0;

    // get buffer size from command line
    on_command_line_editingFinished();
}

download_mgr::~download_mgr()
{
    delete ui;
}

// Console updata ISR handle
void download_mgr::update_Console()
{
    ui->Console->setText(Console.GetText());
    ui->Console->moveCursor(QTextCursor::End);
}

// Event driven ISR for TCP Socket
// Activated when event at TCP Socket occures, like the reception of new data
void download_mgr::TCP_Read_Data()
{
    // Initalize local data buffer
    QByteArray recv_data=0;
    // Check if new bytes are available
    if (tcp_socket->bytesAvailable())
    {
        // Read data from socket
        recv_data=tcp_socket->readAll();

        // Parse data to String
        QString data = recv_data.data();
        // Add data to console memory
        Console.AddText(data+"\n");

        // MPD /////////////////////////////////////////////////////////////////////////////////////////
        if (recv_data.contains("MPD"))
        {
            // Split string into substrings
            // Split is done when detecting space ' ';
            MPD_data=recv_data.split(' ');

            // Number of bitrates with different quality
            // Subtract MPD and the number of segments
            n_bitrates=MPD_data.count()-2;

            // CREATE QUALITY BITRATE HISTOGRAM
            for (int i=1; i<=n_bitrates; i++)
            {
                distribution.insert(i,0);
            }

            // Get the string representation of the number of expected segments
            QByteArray segments = MPD_data.at(1);
            // conver the string to uint
            n_segments=segments.toUInt();
            // Set segment counter at startup to 1
            segment_counter=1;

            // Check if bitrate adaption shall be done
            if (adaptation_on==0)
            {
                // Get the requested bitrate representation from the UI
                req_bitrate=ui->stream_qual->value();

                // Enable user to define bitrate
                if (req_bitrate>n_bitrates)
                {
                    req_bitrate=n_bitrates;
                    ui->stream_qual->setValue(n_bitrates);
                    Console.AddText("Maximum possible quality level"+QString::number(req_bitrate)+"\n");
                }
            }
            // BITRATE ADAPTION
            else
            {
                if(algorithm==0)
                {
                    // For first packet, buffer is empty. Playout will start when N sec were buffered
                    // Fill buffer until start with average
                    // bitrate, which is linear scaled. For playing use the logarithmic approach.
                    // Afterwards playout start, begin with logarithmic processing.
                    // The user does not want to wait for an eternal time to start watching the video
                    req_bitrate=bw_quality_match(avg_data_rate());
                }
            }

            // Send the send command, with the calculated bitrate representation number and the number
            // of the required segment
            QString send = "GET "+QString::number(req_bitrate)+" "+QString::number(segment_counter);
            // Convert String to char array
            QByteArray *command=new QByteArray(send.toLocal8Bit());

            // Send Command to dash_deamon
            if (tcp_socket->write(*command)==-1)
            {
                Console.AddText("ERROR: Unable to send command \n");
            }
            else
            {
                Console.AddText("START video download \n"+send+" \n");
            }

        }

        // DWN /////////////////////////////////////////////////////////////////////////////////////////
        if (recv_data.contains("DWN"))
        {

            // Split received data string
            DWN_data=recv_data.split(' ');

            // Check if other message is included in Buffer with DWN
            quint64 index = 0;
            quint64 DWN_offset=0;

            // Not only DWN packet was received by the TCP Socket
            if (DWN_data.count()>2)
            {
                // Search for position of DWN
                quint64 DWN_offset=DWN_data.indexOf("DWN");
            }

            // Set index to position of DWN segment number
            index = (DWN_data.at(DWN_offset+1)).toUInt();

            // ASK again for segment in case of undefined error
            // Out of order reception not possible, because packets are requested after each other
            // IF DWN DOES NOT CONTAIN EXPECTED NUMBER recall for expected packet number
            if (index!=segment_counter)
            {
                //req_bitrate=n_bitrates;
                QString send = "GET "+QString::number(req_bitrate)+" "+QString::number(segment_counter);
                QByteArray *command=new QByteArray(send.toLocal8Bit());

                if (tcp_socket->write(*command)==-1)
                {
                    Console.AddText("ERROR: Unable to send command \n");
                }
            }
            else
            {
                // All segments that had to be requested were received
                if (index==n_segments)
                {
                    Console.AddText("END video download \n");
                    Console.AddText("Number of packets received: "+QString::number(n_segments)+"\n");
                    Console.AddText("Segment Qualtiy Distribution: \n");

                    // GIVE HISTOGRAM OUT
                    for (int i=1; i<=n_bitrates; i++)
                    {
                        quint64 n_segments=distribution.value(i);
                        Console.AddText("Representation "+QString::number(i)+": "+
                                        QString::number(n_segments)+"segments \n");
                    }

                     // Stop Console auto refresh
                    disconnect(Console_update, SIGNAL(timeout()), this, SLOT(update_Console()));
                    ui->Console->setText(Console.GetText());
                    ui->Console->moveCursor(QTextCursor::End);
                    // Stop Console auto refresh

                }
                else
                {
                    // Check if bitrate adaption shall be done
                    if (adaptation_on==0)
                    {
                        req_bitrate=ui->stream_qual->value();
                    }
                    else
                    {
                        // Determine if playout already started
                        if (playout_buffer_size<=segment_counter*segment_size)
                        {
                            playout_started=1;
                        }

                        // Check if the buffer size is set to be dynamically adjusted or just
                        if (ui->buffer_size_en->isChecked())
                        {
                            max_buffer_size=ui->buffer_size_adju->value();
                        }
                        else
                        {
                            // Get the number of segments that shall be stored in the buffer
                            max_buffer_size=playout_buffer_size/segment_size;
                        }

                        // For first packet, buffer is empty. Playout will start when N sec were buffered
                        // Fill buffer until start with average
                        // bitrate, which is linear scaled. For playing use the logarithmic approach.
                        // Afterwards playout start, begin with logarithmic processing.
                        // The user does not want to wait for an eternal time to start watching the video
                        if (playout_started==0)
                        {
                            req_bitrate=bw_quality_match(avg_data_rate());
                        }
                        else
                        {
                            // Calculate the average bitrate
                            double avg_rate=avg_data_rate();
                            // Calculate the logarithmic adapted bitrate (% of trust)
                            double log_rate=logarithmic_processor(avg_rate);
                            // Match bitrate to requested representation
                            req_bitrate=bw_quality_match(log_rate);
                        }
                    }

                    // Increase number of expected packet
                    segment_counter++;

                    // UPDATE HISTOGRAM
                    quint64 n_seg=(distribution.value(req_bitrate))+1;
                    distribution.insert(req_bitrate,n_seg);

                    // Send command string
                    QString send = "GET "+QString::number(req_bitrate)+" "+QString::number(segment_counter);
                    QByteArray *command=new QByteArray(send.toLocal8Bit());

                    if (tcp_socket->write(*command)==-1)
                    {
                        Console.AddText("ERROR: Unable to send command \n");
                    }
                    else
                    {
                        Console.AddText(send +"\n");
                    }
                }
            }
        }
        // MES /////////////////////////////////////////////////////////////////////////////////////////
        else if (recv_data.contains("MES"))
        {
            if (algorithm==0)
            {
                // push value into end of list
                MES_data.push_back(recv_data);

                // If integration limit size was reached or changed remove first element(s)
                // Dynamical size adjustment
                while (MES_data.count()>integration_limits)
                {
                    // Remove first element
                    MES_data.pop_front();
                }

            }
            else
            {
                // No second algortihm implemented yet
            }
        }
    }
}

void download_mgr::on_Check_Server_IP_clicked()
{
    Console.ClearText();
    // Check if a tcp socket was already defined
    if (socket_setup!=0) delete tcp_socket;
    ui->connect_disp->setText("active");

    // Setup Console update timer
    Console_update = new QTimer(this);
    connect(Console_update, SIGNAL(timeout()), this, SLOT(update_Console()));

    tcp_socket=new QTcpSocket(this);
    tcp_socket->setSocketOption(QAbstractSocket::LowDelayOption,03);

    // Connect Client to Server
    tcp_socket->connectToHost(ui->Server_IP->text(),ui->Server_Port->text().toUInt()
                              ,QIODevice::ReadWrite);

    // Connect Socket to ISR handle
    if(connect(tcp_socket, SIGNAL(readyRead()), this, SLOT(TCP_Read_Data())))
    {
        Console.AddText("Client receive data ISR setup success \n\n");
    }
    else
    {
        Console.AddText("ERROR: Client receive data ISR setup error \n\n");
    }

    // Socket setup done
    socket_setup=1;

    // Start Console auto update timer.
    Console_update->start(ui->Console_refresh->value());
    ui->Console->setText(Console.GetText());
    ui->Console->moveCursor(QTextCursor::End);
}



// Set timer refresh rate
void download_mgr::on_Console_refresh_valueChanged(int arg1)
{
    if(socket_setup==1)Console_update->start(arg1);
}
// Set Integration limits for algorithmus 1
void download_mgr::on_int_limits_valueChanged(int arg1)
{
    integration_limits=arg1;
}

void download_mgr::on_int_limits_editingFinished()
{
}

// Command send button clicked
void download_mgr::on_pushButton_clicked()
{
    if(socket_setup==1)
    {
        playout_started=0;
        // Read Command from Command line
        QByteArray *command=new QByteArray(ui->command_line->text().toLocal8Bit());

        // Send command
        if (tcp_socket->write(*command)==-1)
        {
            Console.AddText("Unable to connect to dash_deamon \n\n");
            disconnect(tcp_socket, SIGNAL(readyRead()), this, SLOT(TCP_Read_Data()));
            Console.AddText("ERROR: Client receive data ISR disconnected \n\n");
        }
        else
        {
            Console.AddText("Connection to dash_deamon active \n\n");
        }
    }
    else Console.AddText("Please setup connection first \n\n");
}

// Get buffer size from command line
void download_mgr::on_command_line_editingFinished()
{
    QByteArray *command=new QByteArray(ui->command_line->text().toLocal8Bit());
    QList<QByteArray> command_string= command->split(' ');
    if (command_string.at(0).contains("CONNECT"))
    {
         playout_buffer_size=(command_string.at(1)).toDouble();
    }
    return;
}

// Enable rate adaptation
void download_mgr::on_Rate_adaptation_clicked()
{
    adaptation_on=ui->Rate_adaptation->checkState();
}

// Calculate quality for next packet that shall be requested!
quint64 download_mgr::bw_quality_match(double data_rate)
{
    int index_max=(MPD_data.count()-2);

    if (index_max>0)
    {
        for (int i=0; i<index_max; i++)
        {
            quint64 q_bitrate=(MPD_data.at(i+2)).toUInt();
            // Check when required bitrate exceeds available bitrate
            double divisor= data_rate/q_bitrate;
            if (divisor<1)
            {
                // Return previos bitrate number as limit
                return (i+1);
                // break loop
                i=index_max;
            }
        }

    }
    else
    {
        return 1;
    }
}

// Calculate average data rate
double download_mgr::avg_data_rate()
{
    average=0;
    int unvalid_entry=0;
    // Derive the number of measurements available for average and calculate the average on their basis
    for (int i=0; i<MES_data.count(); i++)
    {
        // Split values into segments
        QList<QByteArray> l_data=(MES_data.at(i)).split(' ');
        // Check if data packet is valid
        if (l_data.at(0).contains("MES"))
        {
            double bw = l_data.at(1).toDouble();
            // Add values to average
            if (bw>0)
            {
                average+=bw;
            }
            else
            {
                unvalid_entry++;
            }
        }
        else
        {
            // Compute the number of invalid entries in case of any errors occured
            unvalid_entry++;
        }
    }

    // compute average and substract the number of invalid entries from the number of valid entries
    average=(average/(MES_data.count()-unvalid_entry))*1000;
    return average;
}

double download_mgr::logarithmic_processor(double avg_bitrate)
{
    // Calculate stretch factors for system reaction
    double max_log=log10(max_buffer_size);
    // Calculate logratihmic scaling normalized on maximum buffer size
    double scale = 1/max_log;

    // If buffer remains quite full the qualtiy requested is better
    // than when the buffer runs low.
    // It is assumed (for optimal performance) that the bitrate is more or less constant with some temporary breakdowns.
    // The quality significantly decreases when approaching low bitrates.
    // At low bitrates the system can start to swing for some time, but it will remain stable.
    // The buffer size needs to be sufficient big for better granularity.
    // Furthermore the logarithmic scaling shall reduce the number of jumps within the
    // qualtiy of the streamed video
    quint64 index = MES_data.count();
    // Get last MES message received from buffer
    QList<QByteArray> last_MES = (MES_data.at(index-1)).split(' ');

    // Get current number of packets in Buffer
    // Read current buffer size from Messages
    buffer_size=(last_MES.at(2)).toDouble();
    if(playout_started==0)
    {
        // Increment current buffer_size by the size of one segment, because the calculation was forced
        // by the reception of a DWN Message. The next MES buffer statement will be increased by two,
        // but is sent after the DWN Message
        buffer_size+=segment_size;
    }

    // Calculate logarithmus
    double current_log = log10(buffer_size);

    // How many percent of the performance of the average bitrate is trusted?
    // Related to number of packets in buffer
    double percent = current_log*scale;
    double log_bitrate = avg_bitrate*percent;
    return log_bitrate;
}
