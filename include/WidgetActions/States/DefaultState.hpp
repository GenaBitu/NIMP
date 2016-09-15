#pragma once

#include "Global.hpp"

#include "WidgetActions/States/ActionState.hpp"

class DefaultState : public ActionState
{
public:
    DefaultState(ActionWidget* widget, const std::map<std::string, std::tuple<std::string, std::string>>& palette);
    virtual void mousePressEvent(QMouseEvent* event);
};
