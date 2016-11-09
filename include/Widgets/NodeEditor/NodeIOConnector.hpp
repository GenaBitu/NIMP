#pragma once

#include "Global.hpp"

class NodeInputGraphics;
class NodeOutputGraphics;

class NodeIOConnector : public QWidget
{
    Q_OBJECT
public:
    NodeIOConnector(NodeInputGraphics* parent, int x = 0, int y = 0);
    NodeIOConnector(NodeOutputGraphics* parent, int x = 0, int y = 0);
protected:
    virtual void mousePressEvent(QMouseEvent*) override;
    virtual void paintEvent(QPaintEvent*) override;
private:
    void init(int x, int y);
};
