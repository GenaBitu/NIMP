#pragma once

#include "Global.hpp"

class NodeOutput;
class NodePath;
class NodeGraphics;
class NodeInputGraphics;
class NodeIOConnector;

class NodeOutputGraphics : public QWidget
{
    Q_OBJECT
public:
    std::vector<NodePath*> connections;
    NodeOutputGraphics(NodeGraphics* parent, NodeOutput* output, int y);
    void connect();
    void disconnect();
protected:
    friend NodeInputGraphics;
    NodeOutput* output;
    NodeIOConnector* connector;
    virtual void paintEvent(QPaintEvent*);
};
