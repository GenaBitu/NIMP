#pragma once

#include "Global.hpp"

class NodeInput;
class NodeGraphics;
class NodeOutputGraphics;
class NodePath;

class NodeInputGraphics : public QWidget
{
    Q_OBJECT
public:
    NodePath* connection;
    NodeInputGraphics(NodeGraphics* parent, NodeInput* input, int y);
    void connect();
    void disconnect();
protected:
    friend NodeOutputGraphics;
    NodeInput* input;
    virtual void mousePressEvent(QMouseEvent*);
    virtual void paintEvent(QPaintEvent*);
};
