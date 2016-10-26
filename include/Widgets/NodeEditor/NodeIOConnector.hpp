#pragma once

#include "Global.hpp"

class NodeInputGraphics;
class NodeOutputGraphics;

class NodeIOConnector : public QWidget
{
    Q_OBJECT
public:
    NodeIOConnector(NodeInputGraphics* parent, float x = 0, float y = 0);
    NodeIOConnector(NodeOutputGraphics* parent, float x = 0, float y = 0);
protected:
    virtual void paintEvent(QPaintEvent*);
private:
    void init(float x, float y);
};
