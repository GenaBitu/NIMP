#pragma once

#include "Global.hpp"

class NodeOutputGraphics;
class NodeInputGraphics;

class NodePath : public Selectable
{
public:
    NodePath(NodeEditor* parent, NodeOutputGraphics* left, NodeInputGraphics* right);
    NodeOutputGraphics* left;
    NodeInputGraphics* right;
protected:
    virtual void paintEvent(QPaintEvent*);
};
