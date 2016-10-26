#pragma once

#include "Global.hpp"

#include "Widgets/NodeEditor/NodeGraphics.hpp"
#include "Widgets/NodeEditor/NodeInputGraphics.hpp"
#include "Widgets/NodeEditor/NodeIOConnector.hpp"
#include "Widgets/NodeEditor/NodeOutputGraphics.hpp"
#include "Widgets/NodeEditor/NodePath.hpp"

#include "WidgetActions/ActionWidgetContainer.hpp"

class NodeEditor : public ActionWidgetContainer
{
    Q_OBJECT
public:
    NodeEditor();
protected:
    friend NodeInputGraphics;
    friend NodeOutputGraphics;
    std::vector<NodeGraphics*> nodes;
    std::vector<NodePath*> paths;
};
