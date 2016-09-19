#pragma once

#include "Global.hpp"

class NodeConnectorRight;
class NodeConnectorLeft;

class NodePath : public Selectable
{
public:
    NodePath(NodeEditor* parent, NodeConnectorRight* left, NodeConnectorLeft* right);
protected:
    NodeConnectorRight* left;
    NodeConnectorLeft* right;
    virtual void paintEvent(QPaintEvent*);
};
