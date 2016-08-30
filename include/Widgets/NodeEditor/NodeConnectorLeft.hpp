#pragma once

#include "Global.hpp"

class NodeConnectorLeft : public QWidget
{
public:
    NodeConnectorLeft(QWidget* parent, NodeInput* input, int y);
protected:
    NodeInput* input;
    virtual void paintEvent(QPaintEvent*);
};
