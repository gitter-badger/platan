#-------------------------------------------------
#
# Project created by QtCreator 2014-02-23T13:22:02
#
#-------------------------------------------------

QT       += widgets testlib sql

TARGET = tst_sqlite
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11 -Werror=return-type

SOURCES += \
    tst_sqlite.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"


include(../AccountingMain/SQLiteWrapper/SQLiteWrapper.pri)

HEADERS +=
