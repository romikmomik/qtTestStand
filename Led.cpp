#include <QString>
#include <QDebug>

#include "Led.h"

qtLed::qtLed():
    mRedFile("/sys/class/leds/led_red/brightness"),
    mGreenFile("/sys/class/leds/led_green/brightness")
{
    if (!mRedFile.open(QIODevice::WriteOnly|QIODevice::Truncate|QIODevice::Unbuffered|QIODevice::Text))
    {
        qDebug()<< "No LED RED"<< endl;
    }
    if (!mGreenFile.open(QIODevice::WriteOnly|QIODevice::Truncate|QIODevice::Unbuffered|QIODevice::Text))
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

        int red = color&0x01;
        int green = (color&0x02)>>1;
        qDebug()<< "Set G("<<green<<") R("<<red<<")"<< endl;
        mGreenFile.write(QString::number(green).toStdString().data());
        mRedFile.write(QString::number(red).toStdString().data());
        mGreenFile.flush();
        mRedFile.flush();
    }
}

void qtLed::blink(led_color color,int count)
{

}
