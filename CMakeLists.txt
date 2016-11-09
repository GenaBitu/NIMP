cmake_minimum_required(VERSION 3.6)
project(NIMP)

set(WARNINGS "-Wnon-virtual-dtor -Winit-self -Wredundant-decls -Wcast-align -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Wmain -Wfatal-errors -Wextra -Wall -Weffc++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${WARNINGS} -std=c++11")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_library(BlendSplitter NAMES BlendSplitter PATHS /usr/lib)

find_package(OpenGL REQUIRED)
find_package(Qt5 REQUIRED COMPONENTS Core Widgets OpenGL)

include_directories(include)

set(SOURCE_FILES
    include/Nodes/BMPinput.hpp
    include/Nodes/CanvasNode.hpp
    include/NodeSystem/NodeDataTypes/NodeDataImage.hpp
    include/NodeSystem/NodeDataTypes/NodeDataInt.hpp
    include/NodeSystem/NodeDataTypes/NodeDataMonochrome.hpp
    include/NodeSystem/NodeInputTypes/NodeInputImage.hpp
    include/NodeSystem/NodeInputTypes/NodeInputInt.hpp
    include/NodeSystem/NodeInputTypes/NodeInputMonochrome.hpp
    include/NodeSystem/NodeInterfaceTypes/NodeInterfaceBool.hpp
    include/NodeSystem/NodeInterfaceTypes/NodeInterfaceString.hpp
    include/NodeSystem/NodeInterfaceTypes/NodeInterfaceUniqueString.hpp
    include/NodeSystem/NodeOutputTypes/NodeOutputImage.hpp
    include/NodeSystem/NodeOutputTypes/NodeOutputInt.hpp
    include/NodeSystem/NodeOutputTypes/NodeOutputMonochrome.hpp
    include/NodeSystem/Node.hpp
    include/NodeSystem/NodeData.hpp
    include/NodeSystem/NodeDataTypes.hpp
    include/NodeSystem/NodeInput.hpp
    include/NodeSystem/NodeInputTypes.hpp
    include/NodeSystem/NodeInterface.hpp
    include/NodeSystem/NodeInterfaceTypes.hpp
    include/NodeSystem/NodeIO.hpp
    include/NodeSystem/NodeOutput.hpp
    include/NodeSystem/NodeOutputTypes.hpp
    include/NodeSystem/RowSelector.hpp
    include/Registry/ExtrinsicRegistry.hpp
    include/Registry/GuiSettings.hpp
    include/Registry/IntrinsicRegistry.hpp
    include/Registry/RegistryNotifier.hpp
    include/WidgetActions/States/ActionState.hpp
    include/WidgetActions/States/DefaultState.hpp
    include/WidgetActions/States/DraggedState.hpp
    include/WidgetActions/States/SelectedState.hpp
    include/WidgetActions/ActionWidget.hpp
    include/WidgetActions/ActionWidgetContainer.hpp
    include/WidgetActions/Draggable.hpp
    include/WidgetActions/Selectable.hpp
    include/WidgetActions/States.hpp
    include/Widgets/NodeEditor/NodeInterfaceGraphicsTypes/NodeInterfaceBoolGraphics.hpp
    include/Widgets/NodeEditor/NodeInterfaceGraphicsTypes/NodeInterfaceStringGraphics.hpp
    include/Widgets/NodeEditor/NodeInterfaceGraphicsTypes/NodeInterfaceUniqueStringGraphics.hpp
    include/Widgets/NodeEditor/NodeGraphics.hpp
    include/Widgets/NodeEditor/NodeInputGraphics.hpp
    include/Widgets/NodeEditor/NodeInterfaceGraphics.hpp
    include/Widgets/NodeEditor/NodeInterfaceGraphicsTypes.hpp
    include/Widgets/NodeEditor/NodeIOConnector.hpp
    include/Widgets/NodeEditor/NodeOutputGraphics.hpp
    include/Widgets/NodeEditor/NodePath.hpp
    include/Widgets/NodeEditor/NodePathCutter.hpp
    include/Widgets/NodeEditor/TempPath.hpp
    include/Widgets/Canvas.hpp
    include/Widgets/NodeEditor.hpp
    include/Global.hpp
    include/Main.hpp
    include/Nodes.hpp
    include/NodeSystem.hpp
    include/Registry.hpp
    include/Texture.hpp
    include/WidgetActions.hpp
    include/Widgets.hpp
    src/Nodes/BMPinput.cpp
    src/Nodes/CanvasNode.cpp
    src/NodeSystem/NodeDataTypes/NodeDataImage.cpp
    src/NodeSystem/NodeDataTypes/NodeDataInt.cpp
    src/NodeSystem/NodeDataTypes/NodeDataMonochrome.cpp
    src/NodeSystem/NodeInputTypes/NodeInputImage.cpp
    src/NodeSystem/NodeInputTypes/NodeInputInt.cpp
    src/NodeSystem/NodeInputTypes/NodeInputMonochrome.cpp
    src/NodeSystem/NodeInterfaceTypes/NodeInterfaceBool.cpp
    src/NodeSystem/NodeInterfaceTypes/NodeInterfaceString.cpp
    src/NodeSystem/NodeInterfaceTypes/NodeInterfaceUniqueString.cpp
    src/NodeSystem/NodeOutputTypes/NodeOutputImage.cpp
    src/NodeSystem/NodeOutputTypes/NodeOutputInt.cpp
    src/NodeSystem/NodeOutputTypes/NodeOutputMonochrome.cpp
    src/NodeSystem/Node.cpp
    src/NodeSystem/NodeData.cpp
    src/NodeSystem/NodeInput.cpp
    src/NodeSystem/NodeInterface.cpp
    src/NodeSystem/NodeIO.cpp
    src/NodeSystem/NodeOutput.cpp
    src/Registry/ExtrinsicRegistry.cpp
    src/Registry/GuiSettings.cpp
    src/Registry/IntrinsicRegistry.cpp
    src/Registry/RegistryNotifier.cpp
    src/WidgetActions/States/ActionState.cpp
    src/WidgetActions/States/DefaultState.cpp
    src/WidgetActions/States/DraggedState.cpp
    src/WidgetActions/States/SelectedState.cpp
    src/WidgetActions/ActionWidget.cpp
    src/WidgetActions/ActionWidgetContainer.cpp
    src/WidgetActions/Draggable.cpp
    src/WidgetActions/Selectable.cpp
    src/Widgets/NodeEditor/NodeInterfaceGraphicsTypes/NodeInterfaceBoolGraphics.cpp
    src/Widgets/NodeEditor/NodeInterfaceGraphicsTypes/NodeInterfaceStringGraphics.cpp
    src/Widgets/NodeEditor/NodeInterfaceGraphicsTypes/NodeInterfaceUniqueStringGraphics.cpp
    src/Widgets/NodeEditor/NodeGraphics.cpp
    src/Widgets/NodeEditor/NodeInputGraphics.cpp
    src/Widgets/NodeEditor/NodeInterfaceGraphics.cpp
    src/Widgets/NodeEditor/NodeIOConnector.cpp
    src/Widgets/NodeEditor/NodeOutputGraphics.cpp
    src/Widgets/NodeEditor/NodePath.cpp
    src/Widgets/NodeEditor/NodePathCutter.cpp
    src/Widgets/NodeEditor/TempPath.cpp
    src/Widgets/Canvas.cpp
    src/Widgets/NodeEditor.cpp
    src/Main.cpp
    src/Registry.cpp
    src/Texture.cpp)

set(RESOURCE_FILES
    images.qrc)

add_executable(NIMP ${SOURCE_FILES} ${RESOURCE_FILES})

add_custom_command(
    TARGET NIMP POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/resources
            $<TARGET_FILE_DIR:NIMP>)

target_link_libraries(NIMP ${OPENGL_LIBRARIES} Qt5::Core Qt5::Widgets Qt5::OpenGL ${BlendSplitter})
