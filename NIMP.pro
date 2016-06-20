#-------------------------------------------------
#
# Project created by QtCreator 2016-01-14T16:53:38
#
#-------------------------------------------------

QT       += core widgets opengl

TARGET = NIMP

TEMPLATE = app

CONFIG += c++11

QMAKE_CXXFLAGS += -std=c++11 -Wnon-virtual-dtor -Winit-self -Wredundant-decls -Wcast-align -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Wmain -std=c++11 -Wfatal-errors -Wextra -Wall

INCLUDEPATH += BlendSplitter/include

DEPENDPATH += BlendSplitter/include

LIBS += -L$$PWD/BlendSplitter/lib -lBlendSplitter

resource_files.path = $$OUT_PWD
resource_files.files = $$PWD/resources/tex2D.bmp
INSTALLS += resource_files

SOURCES += \
    src/Main.cpp \
    src/Canvas.cpp \
    src/Node.cpp \
    src/NodeEditor.cpp \
    src/NodeInput.cpp \
    src/NodeOutput.cpp \
    src/Texture.cpp

HEADERS  += \
    include/Main.hpp \
    include/Canvas.hpp \
    include/Global.hpp \
    include/Node.hpp \
    include/NodeEditor.hpp \
    include/NodeInput.hpp \
    include/NodeOutput.hpp \
    include/Texture.hpp

RESOURCES += \
    images.qrc
