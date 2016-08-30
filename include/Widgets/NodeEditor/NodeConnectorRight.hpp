#pragma once

#include "Global.hpp"

class NodeContainer;

class NodeConnectorRight : public QWidget
{
public:
    NodeConnectorRight(NodeContainer* parent, NodeOutput* output, float y);
protected:
    NodeOutput* output;
    virtual void paintEvent(QPaintEvent*);
};
