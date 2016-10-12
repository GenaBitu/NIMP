#pragma once

#include "Global.hpp"

class NodeInputGraphics;
class NodeOutputGraphics;

class NodeGraphics : public Draggable
{
public:
    NodeGraphics(NodeEditor* parent, Node* node);
    void buildPaths();
protected:
    friend NodeInputGraphics;
    Node* node;
    std::vector<NodeInputGraphics*> inputs;
    std::vector<NodeOutputGraphics*> outputs;
    virtual void mouseReleaseEvent(QMouseEvent* event);
    virtual void paintEvent(QPaintEvent*);
    void updateConnections();
    void repaintConnections();
};
