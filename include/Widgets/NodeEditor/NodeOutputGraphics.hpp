#pragma once

#include "Global.hpp"

class NodeGraphics;
class NodePath;
class NodeInputGraphics;

class NodeOutputGraphics : public QWidget
{
public:
    NodePath* path;
    NodeOutputGraphics(NodeGraphics* parent, NodeOutput* output, int y);
protected:
    friend NodeInputGraphics;
    NodeOutput* output;
    virtual void paintEvent(QPaintEvent*);
};
