#-------------------------------------------------
#
# Project created by QtCreator 2016-05-04T17:09:54
#
#-------------------------------------------------
QT       += multimedia
QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    son.cpp \
    info.cpp \
    sur.cpp \
    dor.cpp \
    sick.cpp \
    tool.cpp \
    ces.cpp \
    floormap.cpp \
    test.cpp \
    calculator.cpp \
    data.cpp \
    alarmclock.cpp \
    medicalhelp.cpp \
    key.cpp \
    th.cpp \
    bloodpressure.cpp \
    bloodglucose.cpp \
    pulse.cpp

HEADERS  += mainwindow.h \
    son.h \
    info.h \
    sur.h \
    dor.h \
    sick.h \
    tool.h \
    ces.h \
    floormap.h \
    test.h \
    QtNetworUtils.h \
    calculator.h \
    data.h \
    alarmclock.h \
    medicalhelp.h \
    key.h \
    th.h \
    bloodpressure.h \
    bloodglucose.h \
    pulse.h

FORMS    += mainwindow.ui \
    son.ui \
    info.ui \
    sur.ui \
    dor.ui \
    sick.ui \
    tool.ui \
    ces.ui \
    test.ui \
    calculator.ui \
    data.ui \
    alarmclock.ui \
    medicalhelp.ui \
    key.ui \
    th.ui \
    bloodpressure.ui \
    bloodglucose.ui \
    pulse.ui

RESOURCES += \
    img.qrc
