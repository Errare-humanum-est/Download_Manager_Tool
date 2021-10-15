/********************************************************************************
** Form generated from reading UI file 'download_mgr.ui'
**
** Created: Thu Jul 3 12:24:52 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOWNLOAD_MGR_H
#define UI_DOWNLOAD_MGR_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QMenuBar>
#include <QPushButton>
#include <QSpacerItem>
#include <QSpinBox>
#include <QStatusBar>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_download_mgr
{
public:
    QWidget *centralWidget;
    QTextEdit *Console;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_43;
    QHBoxLayout *horizontalLayout_42;
    QLabel *label_2;
    QLineEdit *Server_IP;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *Check_Server_IP;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_44;
    QHBoxLayout *horizontalLayout_41;
    QLabel *label;
    QLineEdit *Server_Port;
    QSpacerItem *horizontalSpacer_14;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *connect_disp;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QSpinBox *Console_refresh;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *command_line;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *Rate_adaptation;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *buffer_size_en;
    QSpinBox *buffer_size_adju;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QSpinBox *stream_qual;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QSpinBox *int_limits;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *download_mgr)
    {
        if (download_mgr->objectName().isEmpty())
            download_mgr->setObjectName(QString::fromUtf8("download_mgr"));
        download_mgr->resize(580, 697);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(download_mgr->sizePolicy().hasHeightForWidth());
        download_mgr->setSizePolicy(sizePolicy);
        download_mgr->setMinimumSize(QSize(580, 697));
        download_mgr->setMaximumSize(QSize(580, 697));
        centralWidget = new QWidget(download_mgr);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMinimumSize(QSize(580, 650));
        centralWidget->setMaximumSize(QSize(580, 650));
        Console = new QTextEdit(centralWidget);
        Console->setObjectName(QString::fromUtf8("Console"));
        Console->setGeometry(QRect(11, 239, 561, 400));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Console->sizePolicy().hasHeightForWidth());
        Console->setSizePolicy(sizePolicy1);
        Console->setMinimumSize(QSize(0, 400));
        Console->setMaximumSize(QSize(1012, 1000));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 0, 561, 222));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_43 = new QHBoxLayout();
        horizontalLayout_43->setSpacing(6);
        horizontalLayout_43->setObjectName(QString::fromUtf8("horizontalLayout_43"));
        horizontalLayout_43->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_42 = new QHBoxLayout();
        horizontalLayout_42->setSpacing(6);
        horizontalLayout_42->setObjectName(QString::fromUtf8("horizontalLayout_42"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setMinimumSize(QSize(65, 0));

        horizontalLayout_42->addWidget(label_2);

        Server_IP = new QLineEdit(widget);
        Server_IP->setObjectName(QString::fromUtf8("Server_IP"));

        horizontalLayout_42->addWidget(Server_IP);


        horizontalLayout_43->addLayout(horizontalLayout_42);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_43->addItem(horizontalSpacer_13);

        Check_Server_IP = new QPushButton(widget);
        Check_Server_IP->setObjectName(QString::fromUtf8("Check_Server_IP"));
        Check_Server_IP->setMinimumSize(QSize(145, 0));

        horizontalLayout_43->addWidget(Check_Server_IP);


        verticalLayout->addLayout(horizontalLayout_43);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_44 = new QHBoxLayout();
        horizontalLayout_44->setSpacing(6);
        horizontalLayout_44->setObjectName(QString::fromUtf8("horizontalLayout_44"));
        horizontalLayout_44->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_41 = new QHBoxLayout();
        horizontalLayout_41->setSpacing(6);
        horizontalLayout_41->setObjectName(QString::fromUtf8("horizontalLayout_41"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setMinimumSize(QSize(65, 0));
        label->setLineWidth(1);
        label->setScaledContents(false);

        horizontalLayout_41->addWidget(label);

        Server_Port = new QLineEdit(widget);
        Server_Port->setObjectName(QString::fromUtf8("Server_Port"));

        horizontalLayout_41->addWidget(Server_Port);


        horizontalLayout_44->addLayout(horizontalLayout_41);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_44->addItem(horizontalSpacer_14);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        connect_disp = new QLabel(widget);
        connect_disp->setObjectName(QString::fromUtf8("connect_disp"));
        connect_disp->setTextFormat(Qt::AutoText);

        horizontalLayout->addWidget(connect_disp);


        horizontalLayout_44->addLayout(horizontalLayout);


        verticalLayout_5->addLayout(horizontalLayout_44);


        verticalLayout->addLayout(verticalLayout_5);


        horizontalLayout_6->addLayout(verticalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_5->addWidget(label_6);

        Console_refresh = new QSpinBox(widget);
        Console_refresh->setObjectName(QString::fromUtf8("Console_refresh"));
        Console_refresh->setMinimum(40);
        Console_refresh->setMaximum(5000);
        Console_refresh->setValue(1000);

        horizontalLayout_5->addWidget(Console_refresh);


        horizontalLayout_6->addLayout(horizontalLayout_5);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        command_line = new QLineEdit(widget);
        command_line->setObjectName(QString::fromUtf8("command_line"));

        horizontalLayout_2->addWidget(command_line);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        Rate_adaptation = new QCheckBox(widget);
        Rate_adaptation->setObjectName(QString::fromUtf8("Rate_adaptation"));

        horizontalLayout_8->addWidget(Rate_adaptation);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        buffer_size_en = new QCheckBox(widget);
        buffer_size_en->setObjectName(QString::fromUtf8("buffer_size_en"));

        horizontalLayout_7->addWidget(buffer_size_en);

        buffer_size_adju = new QSpinBox(widget);
        buffer_size_adju->setObjectName(QString::fromUtf8("buffer_size_adju"));
        buffer_size_adju->setMaximum(200);
        buffer_size_adju->setValue(50);

        horizontalLayout_7->addWidget(buffer_size_adju);


        horizontalLayout_8->addLayout(horizontalLayout_7);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        stream_qual = new QSpinBox(widget);
        stream_qual->setObjectName(QString::fromUtf8("stream_qual"));
        stream_qual->setMaximum(10);
        stream_qual->setValue(6);

        horizontalLayout_4->addWidget(stream_qual);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        int_limits = new QSpinBox(widget);
        int_limits->setObjectName(QString::fromUtf8("int_limits"));
        int_limits->setMinimum(1);
        int_limits->setMaximum(200);
        int_limits->setValue(20);

        horizontalLayout_3->addWidget(int_limits);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout_4->addLayout(verticalLayout_2);

        download_mgr->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(download_mgr);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 580, 25));
        download_mgr->setMenuBar(menuBar);
        statusBar = new QStatusBar(download_mgr);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        download_mgr->setStatusBar(statusBar);

        retranslateUi(download_mgr);

        QMetaObject::connectSlotsByName(download_mgr);
    } // setupUi

    void retranslateUi(QMainWindow *download_mgr)
    {
        download_mgr->setWindowTitle(QApplication::translate("download_mgr", "download_mgr", 0));
        label_2->setText(QApplication::translate("download_mgr", "Server IP", 0));
        Server_IP->setText(QApplication::translate("download_mgr", "127.0.0.1", 0));
        Check_Server_IP->setText(QApplication::translate("download_mgr", "Setup", 0));
        label->setText(QApplication::translate("download_mgr", "Port", 0));
        Server_Port->setText(QApplication::translate("download_mgr", "3001", 0));
        label_3->setText(QApplication::translate("download_mgr", "Connection", 0));
        connect_disp->setText(QApplication::translate("download_mgr", "unactive", 0));
        label_6->setText(QApplication::translate("download_mgr", "Console update (ms)", 0));
        command_line->setText(QApplication::translate("download_mgr", "CONNECT 6.0 http://kufstein2.lmt.ei.tum.de/short1/", 0));
        pushButton->setText(QApplication::translate("download_mgr", "Send Command", 0));
        Rate_adaptation->setText(QApplication::translate("download_mgr", "Enable Rate adaptation", 0));
        buffer_size_en->setText(QApplication::translate("download_mgr", "Adjust buffer size", 0));
        label_5->setText(QApplication::translate("download_mgr", "Set Stream Qualtiy (no Rate adaptation)", 0));
        label_4->setText(QApplication::translate("download_mgr", "MES number for average", 0));
    } // retranslateUi

};

namespace Ui {
    class download_mgr: public Ui_download_mgr {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOAD_MGR_H
