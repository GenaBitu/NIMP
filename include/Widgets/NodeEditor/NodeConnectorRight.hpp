#pragma once

#include "Global.hpp"

class NodeGraphics;
class NodePath;
class NodeConnectorLeft;

class NodeConnectorRight : public QWidget
{
public:
    NodePath* path;
    NodeConnectorRight(NodeGraphics* parent, NodeOutput* output, int y);
protected:
    friend NodeConnectorLeft;
    NodeOutput* output;
    virtual void paintEvent(QPaintEvent*);
};
