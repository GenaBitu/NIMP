#pragma once

#include "Global.hpp"

class NodeInput;

class NodeConnectorLeft : public QWidget
{
    Q_OBJECT
public:
    NodeConnectorLeft(QWidget* parent, NodeInput* input, int y);
protected:
    NodeInput* input;
    virtual void paintEvent(QPaintEvent*);
};
