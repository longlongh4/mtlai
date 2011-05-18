#-------------------------------------------------
#
# Project created by QtCreator 2011-01-19T14:01:37
#
#-------------------------------------------------
#include(./browser/mtbrowser.pri)
include(./multimedia/mtMultimedia.pri)
include(./common/common.pri)
include(./plugins/mtPlugins.pri)
include(./ui/mtUI.pri)
include(./control/mtControl.pri)
include(./network/mtNetwork.pri)
include(./chat/mtChat.pri)
#include(./libs/sinaTwitterLib/sinaTwitterLib.pri)
QT       += core gui webkit network svg declarative xml xmlpatterns sql

TARGET = mtlai
TEMPLATE = app

SOURCES += main.cpp\

#HEADERS  += mtmainwindow.h \


RESOURCES += \
    MTWindow.qrc

OTHER_FILES += \

win32:release {
        RC_FILE = win/mtlai.rc
}
