#include <QString>
#include "Led.h"

#include <QDebug>
qtLed::qtLed():
    mRedFile("/sys/class/leds/led_red/brightness"),
    mGreenFile("/sys/class/leds/led_green/brightness")
{
    if (!mRedFile.open(QIODevice::ReadWrite|QIODevice::Truncate|QIODevice::Unbuffered|QIODevice::Text))
    {
        qDebug()<< "No LED RED"<< endl;
    }
    if (!mGreenFile.open(QIODevice::ReadWrite|QIODevice::Truncate|QIODevice::Unbuffered|QIODevice::Text))
    {
        qDebug()<< "No LED GREEN"<< endl;
    }
};
qtLed::~qtLed(){
    mRedFile.close();
    mGreenFile.close();
};
void qtLed::setColor(led_color color){
    if (mRedFile.isOpen()||mGreenFile.isOpen()){
        char green = color&0x01;
        char red = (color&0x02)>>1;
        mRedFile.write(&green,1);
        mRedFile.write(&red,1);
    }
}

void qtLed::blink(led_color color,int count)
{

}
