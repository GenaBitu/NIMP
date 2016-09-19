#pragma once

#include "Global.hpp"

class NodeGraphics;
class NodePath;

class NodeConnectorLeft : public QWidget
{
public:
    NodePath* path;
    NodeConnectorLeft(NodeGraphics* parent, NodeInput* input, int y);
    void buildPath();
protected:
    NodeInput* input;
    virtual void paintEvent(QPaintEvent*);
};
