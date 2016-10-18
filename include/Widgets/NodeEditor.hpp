#pragma once

#include "Global.hpp"

#include "Widgets/NodeEditor/NodeGraphics.hpp"
#include "Widgets/NodeEditor/NodeInputGraphics.hpp"
#include "Widgets/NodeEditor/NodeOutputGraphics.hpp"
#include "Widgets/NodeEditor/NodePath.hpp"
#include "Widgets/NodeEditor/TempPath.hpp"

#include "WidgetActions/ActionWidgetContainer.hpp"

class NodeEditor : public ActionWidgetContainer
{
    Q_OBJECT
public:
    TempPath* temp;
    NodeEditor();
protected:
    friend NodeInputGraphics;
    friend NodeOutputGraphics;
    std::vector<NodeGraphics*> nodes;
    std::vector<NodePath*> paths;
};
