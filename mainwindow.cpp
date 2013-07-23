#include <QStatusBar>
#include <QPushButton>
#include <QDebug>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QFont statusBarFont = statusBar()->font();
    statusBarFont.setPointSize(5);
    statusBar()->setFont(statusBarFont);

    showFullScreen();
    leds.setColor(qtLed::GREEN);
    m_buttonsInputFd = ::open("/dev/input/by-path/platform-gpio-keys-event", O_SYNC, O_RDONLY);
    if (m_buttonsInputFd == -1)
        qDebug() << "Cannot open buttons input file"<<endl;

    m_buttonsInputNotifier = new QSocketNotifier(m_buttonsInputFd, QSocketNotifier::Read, this);
    connect(m_buttonsInputNotifier, SIGNAL(activated(int)), this, SLOT(onButtonRead()));
    m_buttonsInputNotifier->setEnabled(true);
}
void MainWindow::onButtonRead()
{
    struct input_event evt;

    if (read(m_buttonsInputFd, reinterpret_cast<char*>(&evt), sizeof(evt)) != sizeof(evt))
    {
        qDebug() << "Incomplete buttons data read"<<endl;
        return;
    }
    if (evt.type != EV_KEY)
    {
        if (evt.type != EV_SYN)
            qDebug() << "Input event type is not EV_KEY or EV_SYN: " << evt.type;
        return;
    }
    QColor backgroundColour;
    backgroundColour.setRgb(0,255,0); //example colour, I could later manage to utilize this variable with a QColorDialog
    QPalette Pal(palette());
    Pal.setColor(QPalette::Button, backgroundColour.rgb());

    switch (evt.code) {
        case KEY_F1:  break;
        case KEY_F2: ui->sw2Button->setAutoFillBackground(true);
                      ui->sw2Button->setPalette(Pal);
                    break;
        case KEY_F3: ui->sw3Button->setAutoFillBackground(true);
                    ui->sw3Button->setPalette(Pal);
                break;
        case KEY_F4: ui->sw4Button->setAutoFillBackground(true);
                ui->sw4Button->setPalette(Pal);
            break;
        case KEY_F5:  ui->sw5Button->setAutoFillBackground(true);
                    ui->sw5Button->setPalette(Pal);
            break;
        case KEY_F6:  ui->sw6Button->setAutoFillBackground(true);
        ui->sw6Button->setPalette(Pal); break;
        case KEY_F7:  ui->sw7Button->setAutoFillBackground(true);
        ui->sw7Button->setPalette(Pal); break;

    }
}

MainWindow::~MainWindow()
{
    leds.setColor(qtLed::RED);
    delete ui;
}
