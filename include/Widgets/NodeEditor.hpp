#pragma once

#include "Global.hpp"

#include "Widgets/NodeEditor/NodeGraphics.hpp"
#include "Widgets/NodeEditor/NodeInputGraphics.hpp"
#include "Widgets/NodeEditor/NodeIOConnector.hpp"
#include "Widgets/NodeEditor/NodeOutputGraphics.hpp"
#include "Widgets/NodeEditor/NodePath.hpp"
#include "Widgets/NodeEditor/NodePathCutter.hpp"
#include "Widgets/NodeEditor/TempPath.hpp"

#include "WidgetActions/ActionWidgetContainer.hpp"

class NodeEditor : public ActionWidgetContainer
{
    Q_OBJECT
public:
    NodeEditor();
protected:
    friend NodeInputGraphics;
    friend NodeOutputGraphics;
    friend TempPath;
    std::vector<NodeGraphics*> nodes;
    void mousePressEvent(QMouseEvent* event);
};
