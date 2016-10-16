#pragma once

#include "Global.hpp"

#include "WidgetActions/Draggable.hpp"

class Node;
class NodeEditor;
class NodeInputGraphics;
class NodeOutputGraphics;

class NodeGraphics : public Draggable
{
    Q_OBJECT
public:
    std::vector<NodeInputGraphics*> inputs;
    std::vector<NodeOutputGraphics*> outputs;
    NodeGraphics(NodeEditor* parent, Node* node);
    void rebuildConnections();
protected slots:
    void reposition();
protected:
    Node* node;
    virtual void mouseReleaseEvent(QMouseEvent* event);
    virtual void moveEvent(QMoveEvent*);
    virtual void paintEvent(QPaintEvent*);
    void updateConnections();
};
