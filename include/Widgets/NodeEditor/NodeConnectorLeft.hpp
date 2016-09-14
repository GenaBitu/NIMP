#pragma once

#include "Global.hpp"

class NodeGraphics;
class NodePath;

class NodeConnectorLeft : public QWidget
{
public:
    NodeConnectorLeft(NodeGraphics* parent, NodeInput* input, int y);
    void buildPath();
protected:
    NodeInput* input;
    NodePath* path;
    virtual void paintEvent(QPaintEvent*);
};
