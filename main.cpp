#include <QApplication>
#include <QStyleFactory>
#include <QWSServer>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
#ifdef Q_WS_QWS
    QWSServer::setCursorVisible( false );
#endif
    a.setStyle(QStyleFactory::create("Cleanlooks"));

    MainWindow w;
    w.show();
    
    return a.exec();
}
