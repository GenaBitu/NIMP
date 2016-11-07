#pragma once

#include "Global.hpp"

#include "Widgets/NodeEditor/NodeInterfaceGraphicsTypes.hpp"

#include "Widgets/NodeEditor/NodeGraphics.hpp"
#include "Widgets/NodeEditor/NodeInputGraphics.hpp"
#include "Widgets/NodeEditor/NodeInterfaceGraphics.hpp"
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
    static void populateBar(SwitchingBar* bar, QWidget* widget);
public slots:
    void addNode(Node* node);
protected:
    friend NodeGraphics;
    friend NodeInputGraphics;
    friend NodeOutputGraphics;
    friend NodePath;
    friend NodePathCutter;
    friend TempPath;
    std::vector<NodeGraphics*> nodes;
    std::unordered_set<NodePath*> paths;
    void mousePressEvent(QMouseEvent* event);
};
