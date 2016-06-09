#-------------------------------------------------
#
# Project created by QtCreator 2016-01-14T16:53:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NIMP

TEMPLATE = app

CONFIG += c++11

QMAKE_CXXFLAGS += -std=c++11 -Wnon-virtual-dtor -Winit-self -Wredundant-decls -Wcast-align -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Wmain -std=c++11 -Wfatal-errors -Wextra -Wall

INCLUDEPATH += BlendSplitter/include

DEPENDPATH += BlendSplitter/include

LIBS += -L$$PWD/BlendSplitter/lib -lBlendSplitter

SOURCES += \
    src/Main.cpp \
    src/Canvas.cpp \
    src/Image.cpp

HEADERS  += \
    include/Main.hpp \
    include/Canvas.hpp \
    include/Global.hpp \
    include/Image.hpp

RESOURCES += \
    images.qrc
