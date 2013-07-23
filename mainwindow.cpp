#include <QStatusBar>
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
}

MainWindow::~MainWindow()
{
    delete ui;
}
