#ifndef SERIAL_REPEAT_H
#define SERIAL_REPEAT_H

#include <QThread>
#include <QObject>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

#include <windows.h>
#include <ctime>

class SerialRepeat : public QThread
{
    Q_OBJECT
signals:
    void sendSignal(int n);
public:
    SerialRepeat();
    void run() // Thread
    {
        while(1)
        {
            double start = clock();
            if(_mbShutDownSignal)break;
            if(!_mbSendFlag){
                QThread::msleep(1);
                continue;
            }

            // Send
            sendData();
            QThread::msleep(_mdDelay);
            double end = clock();
            qDebug() << 1000/(end-start)<<"Hz" ;
        }
    }
private:
    bool _mbShutDownSignal = false;
    double _mdDelay = 1000;
    bool _mbSendFlag = false;

    void sendData(void);
public:
    void shutdownThread(void){_mbShutDownSignal = true;}
    void setStartFlag(bool bFlag){_mbSendFlag = bFlag;}
    void setRepeatHz(int nHz);
};

#endif // SERIAL_REPEAT_H
