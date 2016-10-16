#pragma once

#include "Global.hpp"

class NodeInput;
class NodeGraphics;
class NodeOutputGraphics;
class NodePath;

class NodeInputGraphics : public QWidget
{
public:
    NodePath* connection;
    NodeInputGraphics(NodeGraphics* parent, NodeInput* input, int y);
    void connect();
    void disconnect();
protected:
    friend NodeOutputGraphics;
    NodeInput* input;
    virtual void paintEvent(QPaintEvent*);
};
