/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *comboBox_port;
    QComboBox *comboBox_baudrate;
    QPushButton *pushButton_connect;
    QPushButton *pushButton_disconnect;
    QGroupBox *groupBox_transmit;
    QTextBrowser *textBrowser_trans;
    QLineEdit *lineEdit_data_transmit;
    QPushButton *pushButton_send;
    QPushButton *pushButton_stop_send;
    QPushButton *pushButton_clear_trans;
    QGroupBox *groupBox_2;
    QTextBrowser *textBrowser_receive;
    QPushButton *pushButton_clear_receive;
    QGroupBox *groupBox_3;
    QRadioButton *radioButton_mode_normal;
    QRadioButton *radioButton_mode_repeat;
    QLineEdit *lineEdit_hz;
    QLabel *label_4;
    QFrame *line;
    QGroupBox *groupBox_4;
    QPushButton *pushButton_clear_log;
    QTextBrowser *textBrowser_log;
    QPushButton *pushButton_close;
    QLabel *label_5;
    QComboBox *comboBox_dataBits;
    QLabel *label_6;
    QLabel *label_7;
    QComboBox *comboBox_parity;
    QPushButton *pushButton_refreshPort;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(831, 644);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 10, 391, 51));
        QFont font;
        font.setPointSize(28);
        font.setBold(true);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 80, 41, 21));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(false);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 110, 71, 21));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        comboBox_port = new QComboBox(centralwidget);
        comboBox_port->setObjectName("comboBox_port");
        comboBox_port->setGeometry(QRect(90, 80, 121, 22));
        comboBox_baudrate = new QComboBox(centralwidget);
        comboBox_baudrate->addItem(QString());
        comboBox_baudrate->addItem(QString());
        comboBox_baudrate->setObjectName("comboBox_baudrate");
        comboBox_baudrate->setGeometry(QRect(90, 110, 121, 22));
        pushButton_connect = new QPushButton(centralwidget);
        pushButton_connect->setObjectName("pushButton_connect");
        pushButton_connect->setEnabled(true);
        pushButton_connect->setGeometry(QRect(220, 80, 71, 51));
        pushButton_disconnect = new QPushButton(centralwidget);
        pushButton_disconnect->setObjectName("pushButton_disconnect");
        pushButton_disconnect->setGeometry(QRect(300, 80, 71, 51));
        groupBox_transmit = new QGroupBox(centralwidget);
        groupBox_transmit->setObjectName("groupBox_transmit");
        groupBox_transmit->setGeometry(QRect(10, 140, 811, 161));
        textBrowser_trans = new QTextBrowser(groupBox_transmit);
        textBrowser_trans->setObjectName("textBrowser_trans");
        textBrowser_trans->setEnabled(true);
        textBrowser_trans->setGeometry(QRect(10, 50, 711, 101));
        textBrowser_trans->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        textBrowser_trans->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        lineEdit_data_transmit = new QLineEdit(groupBox_transmit);
        lineEdit_data_transmit->setObjectName("lineEdit_data_transmit");
        lineEdit_data_transmit->setGeometry(QRect(10, 20, 711, 22));
        pushButton_send = new QPushButton(groupBox_transmit);
        pushButton_send->setObjectName("pushButton_send");
        pushButton_send->setGeometry(QRect(730, 20, 71, 31));
        pushButton_stop_send = new QPushButton(groupBox_transmit);
        pushButton_stop_send->setObjectName("pushButton_stop_send");
        pushButton_stop_send->setGeometry(QRect(730, 60, 71, 31));
        pushButton_clear_trans = new QPushButton(groupBox_transmit);
        pushButton_clear_trans->setObjectName("pushButton_clear_trans");
        pushButton_clear_trans->setGeometry(QRect(730, 100, 71, 51));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 300, 811, 161));
        textBrowser_receive = new QTextBrowser(groupBox_2);
        textBrowser_receive->setObjectName("textBrowser_receive");
        textBrowser_receive->setGeometry(QRect(10, 20, 711, 131));
        pushButton_clear_receive = new QPushButton(groupBox_2);
        pushButton_clear_receive->setObjectName("pushButton_clear_receive");
        pushButton_clear_receive->setGeometry(QRect(730, 20, 71, 51));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(620, 70, 201, 71));
        radioButton_mode_normal = new QRadioButton(groupBox_3);
        radioButton_mode_normal->setObjectName("radioButton_mode_normal");
        radioButton_mode_normal->setGeometry(QRect(10, 20, 61, 20));
        radioButton_mode_normal->setChecked(true);
        radioButton_mode_normal->setAutoRepeat(false);
        radioButton_mode_repeat = new QRadioButton(groupBox_3);
        radioButton_mode_repeat->setObjectName("radioButton_mode_repeat");
        radioButton_mode_repeat->setGeometry(QRect(10, 40, 91, 21));
        lineEdit_hz = new QLineEdit(groupBox_3);
        lineEdit_hz->setObjectName("lineEdit_hz");
        lineEdit_hz->setGeometry(QRect(100, 40, 71, 22));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(170, 40, 21, 21));
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(false);
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignCenter);
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(0, 460, 831, 21));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(10, 480, 381, 141));
        pushButton_clear_log = new QPushButton(groupBox_4);
        pushButton_clear_log->setObjectName("pushButton_clear_log");
        pushButton_clear_log->setGeometry(QRect(300, 20, 71, 51));
        textBrowser_log = new QTextBrowser(groupBox_4);
        textBrowser_log->setObjectName("textBrowser_log");
        textBrowser_log->setGeometry(QRect(10, 20, 281, 111));
        pushButton_close = new QPushButton(centralwidget);
        pushButton_close->setObjectName("pushButton_close");
        pushButton_close->setGeometry(QRect(760, 10, 61, 51));
        pushButton_close->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(420, 10, 331, 51));
        QFont font3;
        font3.setPointSize(9);
        font3.setBold(true);
        label_5->setFont(font3);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        comboBox_dataBits = new QComboBox(centralwidget);
        comboBox_dataBits->addItem(QString());
        comboBox_dataBits->setObjectName("comboBox_dataBits");
        comboBox_dataBits->setGeometry(QRect(520, 81, 81, 21));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(450, 80, 71, 21));
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(470, 110, 51, 21));
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignCenter);
        comboBox_parity = new QComboBox(centralwidget);
        comboBox_parity->addItem(QString());
        comboBox_parity->setObjectName("comboBox_parity");
        comboBox_parity->setGeometry(QRect(520, 110, 81, 22));
        pushButton_refreshPort = new QPushButton(centralwidget);
        pushButton_refreshPort->setObjectName("pushButton_refreshPort");
        pushButton_refreshPort->setGeometry(QRect(380, 80, 71, 51));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 831, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "CoCEL Serial Terminal v1", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Serial Terminal", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "PORT", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Baud Rate", nullptr));
        comboBox_baudrate->setItemText(0, QCoreApplication::translate("MainWindow", "9600", nullptr));
        comboBox_baudrate->setItemText(1, QCoreApplication::translate("MainWindow", "115200", nullptr));

        pushButton_connect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        pushButton_disconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        groupBox_transmit->setTitle(QCoreApplication::translate("MainWindow", "Transmit", nullptr));
        pushButton_send->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        pushButton_stop_send->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        pushButton_clear_trans->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Receive", nullptr));
        pushButton_clear_receive->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Mode", nullptr));
        radioButton_mode_normal->setText(QCoreApplication::translate("MainWindow", "Normal", nullptr));
        radioButton_mode_repeat->setText(QCoreApplication::translate("MainWindow", "Auto Repeat", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Hz", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Log", nullptr));
        pushButton_clear_log->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        pushButton_close->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Copyright (C) 2024 Sanghyun Park. All right reserved.\n"
"CoCEL @POSTECH\n"
"Contact: pash0302@gmail.com", nullptr));
        comboBox_dataBits->setItemText(0, QCoreApplication::translate("MainWindow", "8", nullptr));

        label_6->setText(QCoreApplication::translate("MainWindow", "Data bits", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Parity", nullptr));
        comboBox_parity->setItemText(0, QCoreApplication::translate("MainWindow", "no parity", nullptr));

        pushButton_refreshPort->setText(QCoreApplication::translate("MainWindow", "Refresh\n"
"PORT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
