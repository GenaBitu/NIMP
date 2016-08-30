#pragma once

#include "Global.hpp"

class NodeConnectorLeft;
class NodeConnectorRight;

class NodeContainer : public QWidget
{
public:
    NodeContainer(NodeEditor* parent, Node* node);
protected:
    Node* node;
    std::vector<NodeConnectorLeft*> inputs;
    std::vector<NodeConnectorRight*> outputs;
    virtual void paintEvent(QPaintEvent*);
    float updateConnections();
};
