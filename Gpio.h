#ifndef GPIO_H
#define GPIO_H
#include <QObject>
#include <QFile>


class qtGpio : public QObject
{
    Q_OBJECT
 public:
    qtGpio(int number);
    ~qtGpio();
    int setDirection(bool in);
    int setValue(bool high);
private:
    int mNumber;
};

#endif // GPIO_H
