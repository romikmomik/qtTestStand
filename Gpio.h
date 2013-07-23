#ifndef GPIO_H
#define GPIO_H
#include <QObject>
#include <QFile>


class qtGpio : public QObject
{
    Q_OBJECT
 public:
    qtGpio();
    ~qtGpio();
};

#endif // GPIO_H
