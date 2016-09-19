#pragma once

#include "Global.hpp"

class NodeConnectorLeft;
class NodeConnectorRight;

class NodeGraphics : public Draggable
{
public:
    NodeGraphics(NodeEditor* parent, Node* node);
    void buildPaths();
protected:
    friend NodeConnectorLeft;
    Node* node;
    std::vector<NodeConnectorLeft*> inputs;
    std::vector<NodeConnectorRight*> outputs;
    virtual void mouseReleaseEvent(QMouseEvent* event);
    virtual void paintEvent(QPaintEvent*);
    int updateConnections();
};
