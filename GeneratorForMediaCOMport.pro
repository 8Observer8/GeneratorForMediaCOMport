#-------------------------------------------------
#
# Project created by QtCreator 2014-09-01T10:27:09
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GeneratorForMediaCOMport
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    Sender.cpp \
    SettingsDialog.cpp

HEADERS  += MainWindow.h \
    Sender.h \
    PortError.h \
    SettingsDialog.h

FORMS    += MainWindow.ui \
    SettingsDialog.ui
