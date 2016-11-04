#pragma once

#include "Global.hpp"

#include "WidgetActions/States/ActionState.hpp"

class DefaultState : public ActionState
{
public:
    DefaultState(ActionWidget* widget);
    DefaultState(const ActionState& other);
    virtual ActionWidget::States getState();
    virtual void mousePressEvent(QMouseEvent* event);
};
