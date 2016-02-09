#-------------------------------------------------
#
# Project created by QtCreator 2016-02-08T17:00:47
#
#-------------------------------------------------

QT       += core gui

CONFIG += qwt
INCLUDEPATH +="/usr/local/qwt-5.2.3/include"
LIBS += -L/usr/local/qwt-5.2.3/lib -lqwt



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qwttestingprj
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
