#pragma once

#include "Global.hpp"

#include "WidgetActions/States/ActionState.hpp"

class DraggedState : public ActionState
{
public:
    DraggedState(ActionWidget* widget);
    DraggedState(const ActionState& other);
    ActionWidget::States getState();
    virtual QColor getColour(std::string colour);
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
};
