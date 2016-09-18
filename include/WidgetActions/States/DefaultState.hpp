#pragma once

#include "Global.hpp"

#include "WidgetActions/States/ActionState.hpp"

class DefaultState : public ActionState
{
public:
    DefaultState(ActionWidget* widget);
    DefaultState(ActionState* other);
    virtual QColor getColour(std::string colour);
    virtual void mousePressEvent(QMouseEvent* event);
};
