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
    Q_DISABLE_COPY(NodeGraphics)
public:
    std::vector<NodeInputGraphics*> inputs;
    std::vector<NodeOutputGraphics*> outputs;
    NodeGraphics(NodeEditor* parent, Node* node);
    void rebuildConnections();
    static void connect(NodeOutputGraphics* left, NodeInputGraphics* right);
protected slots:
    void reposition();
protected:
    Node* node;
    virtual void mouseReleaseEvent(QMouseEvent* event);
    virtual void moveEvent(QMoveEvent*);
    virtual void paintEvent(QPaintEvent*);
    void updateConnections();
};
