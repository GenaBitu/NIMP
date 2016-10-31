#pragma once

#include "Global.hpp"

#include "WidgetActions/Selectable.hpp"

class NodeEditor;
class NodeOutputGraphics;
class NodeInputGraphics;

class NodePath : public Selectable
{
    Q_OBJECT
    Q_DISABLE_COPY(NodePath)
public:
    NodeOutputGraphics* left;
    NodeInputGraphics* right;
    NodePath(NodeEditor* parent, NodeOutputGraphics* left, NodeInputGraphics* right);
    void reposition();
protected:
    QPainterPath* path;
    virtual void paintEvent(QPaintEvent*);
};
