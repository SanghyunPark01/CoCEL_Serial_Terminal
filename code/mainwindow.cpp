#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _mSerialPort(new QSerialPort(this))
{
    ui->setupUi(this);

    initializePortInfo();
    ui->pushButton_disconnect->setEnabled(false);
    ui->pushButton_stop_send->setEnabled(false);

    QObject::connect(_mSerialRepeatProcess, SIGNAL(sendSignal(int)), this, SLOT(getSendSignal(int)));
    _mSerialRepeatProcess->start();

    connect(_mSerialPort, &QSerialPort::readyRead, this, &MainWindow::readSerialData);
    connect(_mSerialPort, &QSerialPort::errorOccurred, this, &MainWindow::handleError);

    addLog(QString("[MODE]Normal"));
}
MainWindow::~MainWindow()
{
    _mSerialRepeatProcess->shutdownThread();
    _mSerialRepeatProcess->wait();
    delete _mSerialRepeatProcess;
    delete ui;
}

void MainWindow::on_pushButton_close_clicked()
{
    _mSerialRepeatProcess->shutdownThread();
    this->close();
}




/* @@@@@@@@@@@@@@@@@@@@@@@@@@@
    Serial Port Initialize
@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        on_pushButton_disconnect_clicked();
        addLog(QString("[ERROR]Serial PORT Error!"));
    }
}
void MainWindow::initializePortInfo(void)
{
    ui->comboBox_port->clear();

    const auto qSerialPortLists = QSerialPortInfo::availablePorts();
    for(const QSerialPortInfo &port : qSerialPortLists)
    {
        ui->comboBox_port->addItem(port.portName());
    }
}
void MainWindow::on_pushButton_connect_clicked()
{
    // PORT name
    _mSerialPort->setPortName(ui->comboBox_port->currentText());

    // Baudrate
    std::string sBaudrate = ui->comboBox_baudrate->currentText().toStdString();
    auto qBaudrate = QSerialPort::Baud115200;
    if(sBaudrate == "115200")qBaudrate = QSerialPort::Baud115200;
    else if(sBaudrate == "9600")qBaudrate = QSerialPort::Baud9600;

    _mSerialPort->setBaudRate(qBaudrate);

    // Data bits
    _mSerialPort->setDataBits(QSerialPort::Data8);

    // Parity
    _mSerialPort->setParity(QSerialPort::NoParity);

    // Flow control
    _mSerialPort->setFlowControl(QSerialPort::NoFlowControl);

    // init
    if(_mSerialPort->open(QIODevice::ReadWrite))
    {
        ui->pushButton_connect->setEnabled(false);
        ui->pushButton_disconnect->setEnabled(true);
        ui->pushButton_refreshPort->setEnabled(false);
        addLog(QString("[PORT]Serial PORT Init Success!"));
        addLog(QString("        ┗ Name: ")+_mSerialPort->portName());
        addLog(QString("        ┗ BaudRate: ")+ui->comboBox_baudrate->currentText());
        addLog(QString("        ┗ DataBits: 8"));
        addLog(QString("        ┗ Parity: No"));
    }
    else
    {
        addLog(QString("[ERROR]Serial PORT Error!"));
    }

}
void MainWindow::on_pushButton_disconnect_clicked()
{
    _mSerialRepeatProcess->setStartFlag(false);

    if(_mSerialPort->isOpen())_mSerialPort->close();

    ui->pushButton_connect->setEnabled(true);
    ui->pushButton_disconnect->setEnabled(false);
    ui->pushButton_refreshPort->setEnabled(true);
    // initializePortInfo();

    addLog(QString("[PORT]Disconnected."));
}
void MainWindow::on_pushButton_refreshPort_clicked()
{
    initializePortInfo();
}




/* @@@@@@@@@@@@@@@@@@@@@@@@@@@
        Serial Transmit
@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
void MainWindow::getSendSignal(int n)
{
    _mSerialPort->write(_mqsTransmitRepeatData.toLocal8Bit());
}
void MainWindow::on_lineEdit_data_transmit_textChanged(const QString &arg1)
{
    _mqsTransmitData = arg1;
}
void MainWindow::on_pushButton_send_clicked()
{
    if(!ui->pushButton_disconnect->isEnabled()){
        addLog(QString("[ERROR]Connect PORT First"));
        return;
    }

    if(_mbRepeatMode)
    {
        int nHz = validHz(ui->lineEdit_hz->text());
        if(nHz == -1)
        {
            addLog(QString("[ERROR]Check Repeat Hz Value"));
            return;
        }

        _mqsTransmitRepeatData = _mqsTransmitData;
        _mSerialRepeatProcess->setRepeatHz(nHz);
        addLog(QString("[MODE]Repeat Hz: ")+QString::number(nHz));

        ui->pushButton_stop_send->setEnabled(true);
        ui->pushButton_send->setEnabled(false);

        _mSerialRepeatProcess->setStartFlag(true);

        return;
    }

    // qDebug()<<_mqsTransmitData;
    _mSerialPort->write(_mqsTransmitData.toLocal8Bit());
    if(!_mqsTransmitData.isEmpty()){
        ui->textBrowser_trans->insertPlainText(QString("\n"));
        ui->textBrowser_trans->insertPlainText(_mqsTransmitData);
    }
    else
    {
        addLog(QString("[WARN]There's No Transmit Data"));
    }
    ui->textBrowser_trans->verticalScrollBar()->setValue(ui->textBrowser_trans->verticalScrollBar()->maximum());
}
void MainWindow::on_pushButton_clear_trans_clicked()
{
    ui->textBrowser_trans->clear();
}

void MainWindow::on_radioButton_mode_normal_pressed()
{
    // qDebug() << "normal mode";
    _mbRepeatMode = false;
    ui->pushButton_stop_send->setEnabled(false);
    ui->pushButton_send->setEnabled(true);
    _mSerialRepeatProcess->setStartFlag(false);

    addLog(QString("[MODE]Normal"));
}
void MainWindow::on_radioButton_mode_repeat_pressed()
{
    // qDebug() << "repeat mode";
    _mbRepeatMode = true;
    addLog(QString("[MODE]Auto Repeat"));
}
void MainWindow::on_pushButton_stop_send_clicked()
{
    ui->pushButton_stop_send->setEnabled(false);
    ui->pushButton_send->setEnabled(true);
    _mSerialRepeatProcess->setStartFlag(false);
}
int MainWindow::validHz(QString qsHz)
{
    std::string sHz = qsHz.toLocal8Bit().data();
    if(sHz.size() == 0)return -1;
    std::string sDatabase = "0123456789";
    for(int i = 0; i < sHz.size(); i++)
    {
        if(sDatabase.find(sHz[i]) == std::string::npos)return -1;
    }

    int nHz = std::stoi(sHz);
    if(nHz == 0)return -1;
    // qDebug() << nHz << "\n";
    return nHz;
}



/* @@@@@@@@@@@@@@@@@@@@@@@@@@@
        Serial Receive
@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

void MainWindow::readSerialData()
{
    const QByteArray data = _mSerialPort->readAll();
    // qDebug() << data.size() << "/" << QString(data);
    ui->textBrowser_receive->insertPlainText(QString(data));
    ui->textBrowser_receive->verticalScrollBar()->setValue(ui->textBrowser_receive->verticalScrollBar()->maximum());
}
void MainWindow::on_pushButton_clear_receive_clicked()
{
    ui->textBrowser_receive->clear();
}






/* @@@@@@@@@@@@@@@@@@@@@@@@@@@
            Log
@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
void MainWindow::addLog(QString qsLog)
{
    ui->textBrowser_log->insertPlainText(QString("\n"));
    ui->textBrowser_log->insertPlainText(qsLog);
    ui->textBrowser_log->verticalScrollBar()->setValue(ui->textBrowser_log->verticalScrollBar()->maximum());
}
void MainWindow::on_pushButton_clear_log_clicked()
{
    ui->textBrowser_log->clear();
}




