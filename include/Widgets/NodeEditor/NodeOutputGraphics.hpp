#pragma once

#include "Global.hpp"

class NodeGraphics;
class NodePath;
class NodeInputGraphics;

class NodeOutputGraphics : public QWidget
{
public:
    std::vector<NodePath*> connections;
    NodeOutputGraphics(NodeGraphics* parent, NodeOutput* output, int y);
    void connect();
    void disconnect();
protected:
    friend NodeInputGraphics;
    NodeOutput* output;
    virtual void paintEvent(QPaintEvent*);
};
