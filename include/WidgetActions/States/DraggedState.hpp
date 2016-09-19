#pragma once

#include "Global.hpp"

#include "WidgetActions/States/ActionState.hpp"

class DraggedState : public ActionState
{
public:
    DraggedState(ActionWidget* widget);
    DraggedState(ActionState* other);
    virtual QColor getColour(std::string colour);
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
};
