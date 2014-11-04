#-------------------------------------------------
#
# Project created by QtCreator 2014-02-23T13:22:02
#
#-------------------------------------------------

QT       += core testlib sql

TARGET = tst_sqlite
CONFIG   += console c++11
CONFIG   -= app_bundle

TEMPLATE = app

QMAKE_CXXFLAGS += -Werror=return-type -g -fprofile-arcs -ftest-coverage -O0
QMAKE_LFLAGS += -g -Wall -fprofile-arcs -ftest-coverage -O0

LIBS += -lgcov

SOURCES += \
    tst_sqlite.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

INCLUDEPATH += ../Platan/SQLiteWrapper \
               ../Platan/PlatanData

include(../Platan/SQLiteWrapper/SQLiteWrapper.pri)
include(../Platan/PlatanData/PlatanData.pri)

HEADERS +=