#pragma once

#include "Global.hpp"

#include "WidgetActions/Selectable.hpp"

class NodeEditor;

class NodePathCutter : public Selectable
{
    Q_OBJECT
    Q_DISABLE_COPY(NodePathCutter)
public:
    NodePathCutter(NodeEditor* parent, QPoint origin);
    ~NodePathCutter();
protected:
    const QPoint origin;
    QPainterPath* path;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    void paintEvent(QPaintEvent*) override;
};
