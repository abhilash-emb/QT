#-------------------------------------------------
#
# Project created by QtCreator 2013-02-23T13:01:48
#
#-------------------------------------------------

QT       += core gui

TARGET = Capsule
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    settings.cpp \
    operator.cpp \
    startweighing.cpp \
    administrator.cpp \
    weighing.cpp \
    unlock.cpp

HEADERS  += mainwindow.h \
    settings.h \
    operator.h \
    startweighing.h \
    administrator.h \
    weighing.h \
    unlock.h

FORMS    += mainwindow.ui \
    operator.ui \
    startweighing.ui \
    weighing.ui \
    settings.ui \
    administrator.ui \
    unlock.ui

RESOURCES += \
    images.qrc

RC_FILE = appicon.rc

QT += sql

include(qext/qextserialport-1.2beta2/src/qextserialport.pri)
