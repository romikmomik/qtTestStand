#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPointer>
#include <QSocketNotifier>
#include "Led.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected slots:
    void onButtonRead();
private:
    Ui::MainWindow *ui;
    qtLed leds;
    int                  m_buttonsInputFd;
    QPointer<QSocketNotifier> m_buttonsInputNotifier;
};

#endif // MAINWINDOW_H
