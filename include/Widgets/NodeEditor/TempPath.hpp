#pragma once

#include "Global.hpp"

class NodeEditor;
class NodeOutputGraphics;
class NodeInputGraphics;

class TempPath : public QWidget
{
    Q_OBJECT
public:
    NodeOutputGraphics* left;
    NodeInputGraphics* right;
    TempPath(NodeEditor* parent, NodeInputGraphics* right);
    TempPath(NodeEditor* parent, NodeOutputGraphics* left);
protected:
    QPainterPath* path;
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent*);
    virtual void paintEvent(QPaintEvent*);
};
