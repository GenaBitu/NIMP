#pragma once

#include "Global.hpp"

#include "WidgetActions/States/ActionState.hpp"

class SelectedState : public ActionState
{
public:
    SelectedState(ActionWidget* widget);
    SelectedState(ActionState* other);
    virtual QColor getColour(std::string colour);
};
