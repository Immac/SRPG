TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
    job.cpp \
    printer.cpp \
    statistic.cpp \
    TinyXml/tinyxml2.cpp \
    Readers/classreader.cpp \
    Readers/classreaderxml.cpp

HEADERS += \
    job.h \
    printer.h \
    statistic.h \
    TinyXml/tinyxml2.h \
    Readers/classreader.h \
    Readers/classreaderxml.h

INCLUDEPATH += C:\Boost\boost_1_55_0
LIBS += C:\boost_lib\libs\date_time\build\gcc-mingw-4.8.0\debug\link-static\threading-multi\libboost_date_time-mgw48-mt-d-1_55.a
