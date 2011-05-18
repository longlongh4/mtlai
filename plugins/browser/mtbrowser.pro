#-------------------------------------------------
#
# Project created by QtCreator 2011-01-19T14:01:37
#
#-------------------------------------------------
QT       += core gui webkit network svg declarative xml xmlpatterns

TEMPLATE = lib
CONFIG +=plugin

SOURCES += \
    mtwebview.cpp \
    mtbrowsertabbar.cpp \
    mtbrowser.cpp \
    mtbrowserplugin.cpp

HEADERS  += \
    mtwebview.h \
    mtbrowsertabbar.h \
    mtbrowser.h \
    mtbrowserplugin.h \
    mtplugininterface.h

RESOURCES += \
    mtBrowser.qrc
