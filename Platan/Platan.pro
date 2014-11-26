TEMPLATE = app

QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG  += ordered c++11 static
unix:CONFIG  += qscintilla2

PRECOMPILED_HEADER = stable.h

QMAKE_CXXFLAGS += -O0 -g -Werror=return-type -Wold-style-cast
QMAKE_CXXFLAGS += -Woverloaded-virtual -Wuninitialized -Werror=uninitialized -Winit-self -Werror=init-self
unix {
  QMAKE_CXXFLAGS += $$system(python3.2-config --cflags)
  QMAKE_CXXFLAGS -= -Wstrict-prototype
  QMAKE_CXXFLAGS -= -O2
  LIBS += $$system(python3.2-config --ldflags)
  DEFINES += PYTHON_API
  INCLUDEPATH += /usr/include/python3.2
}

INCLUDEPATH += SQLiteWrapper \
               PlatanData \
               PlatanUI \
               PlatanWidgets \
               PlatanApp \
               PythonAPI \
               PlatanCSV

include(SQLiteWrapper/SQLiteWrapper.pri)
include(PlatanData/PlatanData.pri)
include(PlatanUI/PlatanUI.pri)
include(PlatanWidgets/PlatanWidgets.pri)
include(PlatanCSV/PlatanCSV.pri)
include(PlatanApp/PlatanApp.pri)
unix:include(PythonAPI/PythonAPI.pri)

win32 {
  LIBS += -LC:/Qt/5.3/mingw482_32/lib/ -lqscintilla2
  INCLUDEPATH += C:/Qt/5.3/mingw482_32/include
  DEPENDPATH += C:/Qt/5.3/mingw482_32/include
  PRE_TARGETDEPS += C:/Qt/5.3/mingw482_32/lib/libqscintilla2.a
}

HEADERS += \
    stable.h
