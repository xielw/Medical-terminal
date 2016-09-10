#-------------------------------------------------
#
# Project created by QtCreator 2016-05-06T15:42:04
#
#-------------------------------------------------

QT       += core gui
QT += network
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestServer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    connection.h \
    QtNetworkUtils.h

FORMS    += mainwindow.ui
