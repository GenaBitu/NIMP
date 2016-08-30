#pragma once

#include "Global.hpp"

class NodeContainer;

class NodeConnectorLeft : public QWidget
{
public:
    NodeConnectorLeft(NodeContainer* parent, NodeInput* input, int y);
protected:
    NodeInput* input;
    virtual void paintEvent(QPaintEvent*);
};
