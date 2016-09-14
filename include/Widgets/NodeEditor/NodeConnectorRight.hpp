#pragma once

#include "Global.hpp"

class NodeGraphics;
class NodePath;
class NodeConnectorLeft;

class NodeConnectorRight : public QWidget
{
public:
    NodeConnectorRight(NodeGraphics* parent, NodeOutput* output, int y);
protected:
    friend NodeConnectorLeft;
    NodeOutput* output;
    NodePath* path;
    virtual void paintEvent(QPaintEvent*);
};
