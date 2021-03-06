TEMPLATE = app

QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG  += c++11 static

VERSION = 0.1

DEFINES += VERSION='\"$${VERSION}\"'

PRECOMPILED_HEADER = stable.h

unix {
  QMAKE_CXXFLAGS += -O0 -g -Werror=return-type -Wold-style-cast
  QMAKE_CXXFLAGS += -Woverloaded-virtual -Wuninitialized -Werror=uninitialized -Winit-self -Werror=init-self
  QMAKE_CXXFLAGS -= -Wstrict-prototype
  QMAKE_CXXFLAGS -= -O2
}

RC_FILE = myapp.rc

INCLUDEPATH += SQLiteWrapper \
               PlatanData \
               PlatanUI \
               PlatanWidgets \
               PlatanApp \
               PlatanCSV

include(SQLiteWrapper/SQLiteWrapper.pri)
include(PlatanData/PlatanData.pri)
include(PlatanUI/PlatanUI.pri)
include(PlatanWidgets/PlatanWidgets.pri)
include(PlatanCSV/PlatanCSV.pri)
include(PlatanApp/PlatanApp.pri)


HEADERS += \
    stable.h

DISTFILES += \
    myapp.rc
