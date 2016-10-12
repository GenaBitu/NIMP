#pragma once

#include "Global.hpp"

class NodeGraphics;
class NodePath;

class NodeInputGraphics : public QWidget
{
public:
    NodePath* path;
    NodeInputGraphics(NodeGraphics* parent, NodeInput* input, int y);
    void buildPath();
protected:
    NodeInput* input;
    virtual void paintEvent(QPaintEvent*);
};
