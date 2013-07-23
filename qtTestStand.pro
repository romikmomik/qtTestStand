#-------------------------------------------------
#
# Project created by QtCreator 2013-07-23T16:41:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtTestStand
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Led.cpp \
    Gpio.cpp

HEADERS  += mainwindow.h \
    Led.h \
    Gpio.h

FORMS    += mainwindow.ui
