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
    Q_DISABLE_COPY(NodeInputGraphics)
public:
    NodePath* connection;
    NodeInputGraphics(NodeGraphics* parent, NodeInput* input, int y);
public slots:
    void reconnect();
protected:
    friend NodeGraphics;
    friend NodeOutputGraphics;
    friend TempPath;
    NodeInput* input;
    NodeIOConnector* connector;
    void connect();
    void disconnect();
    virtual void paintEvent(QPaintEvent*);
};
