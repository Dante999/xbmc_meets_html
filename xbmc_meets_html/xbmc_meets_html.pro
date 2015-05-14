#-------------------------------------------------
#
# Project created by QtCreator 2015-05-10T23:42:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = xbmc_meets_html
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    configfile.cpp \
    fileoperations.cpp \
    moviefolder.cpp \
    moviehtml.cpp \
    nfofile.cpp \
    stringtools.cpp \
    dialog_config.cpp \
    dialog_filebrowser.cpp

HEADERS  += mainwindow.h \
    configfile.h \
    fileoperations.h \
    moviefolder.h \
    moviehtml.h \
    nfofile.h \
    stringtools.h \
    dialog_config.h \
    dialog_filebrowser.h

FORMS    += mainwindow.ui \
    dialog_config.ui \
    dialog_filebrowser.ui
