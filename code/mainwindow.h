#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QString>
#include <QScrollBar>>

#include <string>

#include "serial_repeat.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_connect_clicked();

    void on_pushButton_disconnect_clicked();

    void getSendSignal(int n);
    void readSerialData();
    void handleError(QSerialPort::SerialPortError error);

    void on_pushButton_refreshPort_clicked();

    void on_lineEdit_data_transmit_textChanged(const QString &arg1);

    void on_pushButton_send_clicked();

    void on_pushButton_clear_trans_clicked();

    void on_pushButton_clear_receive_clicked();

    void on_pushButton_close_clicked();

    void on_radioButton_mode_normal_pressed();

    void on_radioButton_mode_repeat_pressed();

    void on_pushButton_clear_log_clicked();

    void on_pushButton_stop_send_clicked();

private:
    Ui::MainWindow *ui;

    SerialRepeat* _mSerialRepeatProcess = new SerialRepeat();
    QSerialPort* _mSerialPort = nullptr;

    QString _mqsTransmitData;
    QString _mqsTransmitRepeatData;

    bool _mbRepeatMode = false;

    void initializePortInfo();
    void addLog(QString qsLog);

    int validHz(QString qsHz);
};
#endif // MAINWINDOW_H
