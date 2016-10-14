#pragma once

#include "Global.hpp"

class NodeOutputGraphics;
class NodeInputGraphics;

class NodePath : public Selectable
{
public:
    NodeOutputGraphics* left;
    NodeInputGraphics* right;
    NodePath(NodeEditor* parent, NodeOutputGraphics* left, NodeInputGraphics* right);
    void reposition();
protected:
    QPainterPath* path;
    virtual void paintEvent(QPaintEvent*);
};
