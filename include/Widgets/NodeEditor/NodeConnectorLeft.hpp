#pragma once

#include "Global.hpp"

class NodeGraphics;

class NodeConnectorLeft : public QWidget
{
public:
    NodeConnectorLeft(NodeGraphics* parent, NodeInput* input, int y);
protected:
    NodeInput* input;
    virtual void paintEvent(QPaintEvent*);
};
