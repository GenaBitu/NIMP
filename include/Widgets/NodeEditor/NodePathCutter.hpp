#pragma once

#include "Global.hpp"

#include "WidgetActions/Selectable.hpp"

class NodeEditor;

class NodePathCutter : public Selectable
{
    Q_OBJECT
public:
    NodePathCutter(NodeEditor* parent, QPoint origin);
protected:
    QPoint origin;
    void mouseReleaseEvent(QMouseEvent*);
    void paintEvent(QPaintEvent*);
};
