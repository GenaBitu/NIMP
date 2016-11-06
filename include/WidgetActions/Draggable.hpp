#pragma once

#include "Global.hpp"

#include "WidgetActions/ActionWidget.hpp"

class Draggable : public ActionWidget
{
    Q_OBJECT
public:
    virtual void changeState(States state);
protected:
    Draggable(ActionWidgetContainer* parent = nullptr);
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
};
