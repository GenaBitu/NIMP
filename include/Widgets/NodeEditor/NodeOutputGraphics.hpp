#pragma once

#include "Global.hpp"

class NodeOutput;
class NodePath;
class NodeGraphics;
class NodeInputGraphics;
class NodeIOConnector;
class TempPath;

class NodeOutputGraphics : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(NodeOutputGraphics)
public:
    std::unordered_set<NodePath*> connections;
    NodeOutputGraphics(NodeGraphics* parent, NodeOutput* output, int y);
    void connect();
    void disconnect();
public slots:
    void reconnect();
protected:
    friend NodeGraphics;
    friend NodeInputGraphics;
    friend TempPath;
    NodeOutput* output;
    NodeIOConnector* connector;
    virtual void paintEvent(QPaintEvent*);
};
