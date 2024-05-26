#include "serial_repeat.h"

SerialRepeat::SerialRepeat() {}
void SerialRepeat::setRepeatHz(int nHz)
{
    _mdDelay = 1.0/((double)nHz*(1));
    _mdDelay *= 1000;
}
void SerialRepeat::sendData(void)
{
    sendSignal(1);
}
