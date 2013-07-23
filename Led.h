#ifndef LED_H
#define LED_H

#include <QObject>
#include <QFile>

class qtLed : public QObject
{
    Q_OBJECT
public:
    enum led_color{
        NONE=0,
        RED,//1
        GREEN,//2
        ORANGE
    };
    qtLed();
    ~qtLed();
    void setColor(led_color color);
    void blink(led_color color, int count);

private:
    QFile mRedFile;
    QFile mGreenFile;
};


#endif // LED_H
