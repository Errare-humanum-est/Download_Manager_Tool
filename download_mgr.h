#ifndef DOWNLOAD_MGR_H
#define DOWNLOAD_MGR_H

#include <QMainWindow>
#include <QtNetwork>
#include <QMap>
#include "debug_window.h"
#include <math.h>

namespace Ui {
class download_mgr;
}

class download_mgr : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit download_mgr(QWidget *parent = 0);
    ~download_mgr();

private slots:
    void on_Check_Server_IP_clicked();
    void TCP_Read_Data();
    void update_Console();

    void on_Console_refresh_valueChanged(int arg1);

    void on_int_limits_editingFinished();

    void on_int_limits_valueChanged(int arg1);

    void on_pushButton_clicked();

    void on_command_line_editingFinished();

    void on_Rate_adaptation_clicked();

    quint64 bw_quality_match(double data_rate);
    double avg_data_rate();
    double logarithmic_processor(double avg_bitrate);

private:
    Ui::download_mgr *ui;

    QTcpSocket *tcp_socket;
    bool socket_setup;

    Debug_Window Console;
    QTimer *Console_update;

    bool adaptation_on;

    quint64 segment_counter;

    quint64 segment_size;

    bool playout_started;

    // Store MPD_data message
    QList<QByteArray> MPD_data;
    quint16 n_bitrates;
    quint64 n_segments;
    // Store MES_data message
    QList<QByteArray> MES_data;
    quint64 req_bitrate;

    double buffer_size;
    double max_buffer_size;
    double playout_buffer_size;

    bool algorithm;

    // MY first alogrithm
    double panic_size;

    // Algorithmus for averaging bitrate and adaption to this
    double average;
    quint64 integration_limits;


    // Store DWN_data message
    QList<QByteArray> DWN_data;

    QMap<quint64,quint64> distribution;


};

#endif // DOWNLOAD_MGR_H
