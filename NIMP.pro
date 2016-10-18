#-------------------------------------------------
#
# Project created by QtCreator 2016-01-14T16:53:38
#
#-------------------------------------------------

QT += core widgets opengl

TARGET = NIMP

TEMPLATE = app

CONFIG += c++11

QMAKE_CXXFLAGS += -std=c++11 -Wnon-virtual-dtor -Winit-self -Wredundant-decls -Wcast-align -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Wmain -std=c++11 -Wfatal-errors -Wextra -Wall

INCLUDEPATH += include

LIBS += -lBlendSplitter

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
    include/NodeSystem/NodeInput.hpp \
    include/NodeSystem/NodeOutput.hpp \
    include/Widgets/Canvas.hpp \
    include/Widgets/NodeEditor.hpp \
    include/NodeSystem/RowSelector.hpp \
    src/NodeSystem/RowSelector.tpp \
    include/NodeSystem/NodeIO.hpp \
    include/Nodes.hpp \
    include/NodeSystem.hpp \
    include/NodeSystem/NodeDataTypes.hpp \
    include/NodeSystem/NodeDataTypes/NodeDataImage.hpp \
    include/NodeSystem/NodeDataTypes/NodeDataInt.hpp \
    include/NodeSystem/NodeDataTypes/NodeDataMonochrome.hpp \
    include/NodeSystem/NodeInputTypes.hpp \
    include/NodeSystem/NodeInputTypes/NodeInputImage.hpp \
    include/NodeSystem/NodeInputTypes/NodeInputInt.hpp \
    include/NodeSystem/NodeInputTypes/NodeInputMonochrome.hpp \
    include/NodeSystem/NodeOutputTypes.hpp \
    include/NodeSystem/NodeOutputTypes/NodeOutputImage.hpp \
    include/NodeSystem/NodeOutputTypes/NodeOutputInt.hpp \
    include/NodeSystem/NodeOutputTypes/NodeOutputMonochrome.hpp \
    include/Widgets.hpp \
    include/Registry.hpp \
    include/Registry/GuiSettings.hpp \
    include/Registry/ExtrinsicRegistry.hpp \
    include/Registry/IntrinsicRegistry.hpp \
    include/Widgets/NodeEditor/NodeGraphics.hpp \
    include/Widgets/NodeEditor/NodePath.hpp \
    include/WidgetActions/ActionWidget.hpp \
    include/WidgetActions.hpp \
    include/WidgetActions/States/ActionState.hpp \
    include/WidgetActions/States/DefaultState.hpp \
    include/WidgetActions/States/SelectedState.hpp \
    include/WidgetActions/Selectable.hpp \
    include/WidgetActions/States.hpp \
    include/WidgetActions/ActionWidgetContainer.hpp \
    include/WidgetActions/States/DraggedState.hpp \
    include/WidgetActions/Draggable.hpp \
    include/Widgets/NodeEditor/NodeInputGraphics.hpp \
    include/Widgets/NodeEditor/NodeOutputGraphics.hpp \
    include/Widgets/NodeEditor/TempPath.hpp

SOURCES += \
    src/Main.cpp \
    src/Texture.cpp \
    src/Nodes/BMPinput.cpp \
    src/Nodes/CanvasNode.cpp \
    src/NodeSystem/Node.cpp \
    src/NodeSystem/NodeData.cpp \
    src/NodeSystem/NodeInput.cpp \
    src/NodeSystem/NodeOutput.cpp \
    src/Widgets/Canvas.cpp \
    src/Widgets/NodeEditor.cpp \
    src/NodeSystem/NodeIO.cpp \
    src/NodeSystem/NodeDataTypes/NodeDataImage.cpp \
    src/NodeSystem/NodeDataTypes/NodeDataInt.cpp \
    src/NodeSystem/NodeDataTypes/NodeDataMonochrome.cpp \
    src/NodeSystem/NodeInputTypes/NodeInputImage.cpp \
    src/NodeSystem/NodeInputTypes/NodeInputInt.cpp \
    src/NodeSystem/NodeInputTypes/NodeInputMonochrome.cpp \
    src/NodeSystem/NodeOutputTypes/NodeOutputImage.cpp \
    src/NodeSystem/NodeOutputTypes/NodeOutputInt.cpp \
    src/NodeSystem/NodeOutputTypes/NodeOutputMonochrome.cpp \
    src/Registry.cpp \
    src/Registry/GuiSettings.cpp \
    src/Registry/ExtrinsicRegistry.cpp \
    src/Registry/IntrinsicRegistry.cpp \
    src/Widgets/NodeEditor/NodeGraphics.cpp \
    src/Widgets/NodeEditor/NodePath.cpp \
    src/WidgetActions/ActionWidget.cpp \
    src/WidgetActions/States/ActionState.cpp \
    src/WidgetActions/States/DefaultState.cpp \
    src/WidgetActions/States/SelectedState.cpp \
    src/WidgetActions/Selectable.cpp \
    src/WidgetActions/ActionWidgetContainer.cpp \
    src/WidgetActions/States/DraggedState.cpp \
    src/WidgetActions/Draggable.cpp \
    src/Widgets/NodeEditor/NodeInputGraphics.cpp \
    src/Widgets/NodeEditor/NodeOutputGraphics.cpp \
    src/Widgets/NodeEditor/TempPath.cpp

RESOURCES += \
    images.qrc
