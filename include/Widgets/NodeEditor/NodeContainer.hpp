#pragma once

#include "Global.hpp"

class NodeConnectorLeft;

class NodeContainer : public QWidget
{
public:
    NodeContainer(NodeEditor* parent, Node* node);
protected:
    Node* node;
    std::vector<NodeConnectorLeft*> inputs;
    virtual void paintEvent(QPaintEvent*);
};
