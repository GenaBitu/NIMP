#pragma once

#include "Global.hpp"

class NodeInputGraphics;
class NodeOutputGraphics;

class NodeGraphics : public Draggable
{
public:
    std::vector<NodeInputGraphics*> inputs;
    std::vector<NodeOutputGraphics*> outputs;
    NodeGraphics(NodeEditor* parent, Node* node);
    //void buildPaths();
    void rebuildConnections();
protected:
    Node* node;
    virtual void mouseReleaseEvent(QMouseEvent* event);
    virtual void paintEvent(QPaintEvent*);
    void updateConnections();
};
