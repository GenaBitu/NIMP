#pragma once

#include "Global.hpp"

class NodeConnectorLeft;

class NodeContainer : public QWidget
{
public:
    NodeContainer(NodeEditor* parent, Node* node);
    static float padding;
    static float cornerRadius;
    static float borderWidth;
    static float headerHeight;
protected:
    Node* node;
    std::vector<NodeConnectorLeft*> inputs;
    virtual void paintEvent(QPaintEvent*);
};
