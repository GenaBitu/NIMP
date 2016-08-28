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

HEADERS  += \
    include/Main.hpp \
    include/Global.hpp \
    include/Texture.hpp \
    include/Nodes/BMPinput.hpp \
    include/Nodes/CanvasNode.hpp \
    include/NodeSystem/Node.hpp \
    include/NodeSystem/NodeData.hpp \
    include/NodeSystem/NodeDataImage.hpp \
    include/NodeSystem/NodeDataInt.hpp \
    include/NodeSystem/NodeDataMonochrome.hpp \
    include/NodeSystem/NodeInput.hpp \
    include/NodeSystem/NodeInputImage.hpp \
    include/NodeSystem/NodeInputInt.hpp \
    include/NodeSystem/NodeInputMonochrome.hpp \
    include/NodeSystem/NodeOutput.hpp \
    include/NodeSystem/NodeOutputImage.hpp \
    include/NodeSystem/NodeOutputInt.hpp \
    include/NodeSystem/NodeOutputMonochrome.hpp \
    include/Widgets/Canvas.hpp \
    include/Widgets/NodeEditor.hpp \
    include/NodeSystem/RowSelector.hpp \
    src/NodeSystem/RowSelector.tpp \
    include/Widgets/NodeEditor/NodeContainer.hpp \
    include/Widgets/NodeEditor/NodeConnectorLeft.hpp \
    include/NodeSystem/NodeIO.hpp

SOURCES += \
    src/Main.cpp \
    src/Texture.cpp \
    src/Nodes/BMPinput.cpp \
    src/Nodes/CanvasNode.cpp \
    src/NodeSystem/Node.cpp \
    src/NodeSystem/NodeData.cpp \
    src/NodeSystem/NodeDataImage.cpp \
    src/NodeSystem/NodeDataInt.cpp \
    src/NodeSystem/NodeDataMonochrome.cpp \
    src/NodeSystem/NodeInput.cpp \
    src/NodeSystem/NodeInputImage.cpp \
    src/NodeSystem/NodeInputInt.cpp \
    src/NodeSystem/NodeInputMonochrome.cpp \
    src/NodeSystem/NodeOutput.cpp \
    src/NodeSystem/NodeOutputImage.cpp \
    src/NodeSystem/NodeOutputInt.cpp \
    src/NodeSystem/NodeOutputMonochrome.cpp \
    src/Widgets/Canvas.cpp \
    src/Widgets/NodeEditor.cpp \
    src/Widgets/NodeEditor/NodeContainer.cpp \
    src/Widgets/NodeEditor/NodeConnectorLeft.cpp \
    src/NodeSystem/NodeIO.cpp

RESOURCES += \
    images.qrc
