#pragma once

#include "Global.hpp"

#include "WidgetActions/Draggable.hpp"
#include "WidgetActions/Selectable.hpp"
#include "WidgetActions/ActionWidgetContainer.hpp"

class Node;
class NodeInput;
class NodeOutput;

class NodeEditor : public ActionWidgetContainer
{
    #include "Widgets/NodeEditor/NodeInputGraphics.hpp"
    #include "Widgets/NodeEditor/NodeOutputGraphics.hpp"
    #include "Widgets/NodeEditor/NodeGraphics.hpp"
    #include "Widgets/NodeEditor/NodePath.hpp"
    Q_OBJECT
public:
    NodeEditor();
protected:
    std::vector<NodeGraphics*> nodes;
    std::vector<NodePath*> paths;
};
