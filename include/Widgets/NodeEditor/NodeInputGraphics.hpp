#pragma once

#include "Global.hpp"

class NodeInput;
class NodeGraphics;
class NodeIOConnector;
class NodeOutputGraphics;
class NodePath;
class TempPath;

class NodeInputGraphics : public QWidget
{
    Q_OBJECT
public:
    NodePath* connection;
    NodeInputGraphics(NodeGraphics* parent, NodeInput* input, int y);
    void connect();
    void disconnect();
protected:
    friend NodeGraphics;
    friend NodeOutputGraphics;
    friend TempPath;
    NodeInput* input;
    NodeIOConnector* connector;
    virtual void paintEvent(QPaintEvent*);
};
