#pragma once

#include "Global.hpp"

#include "WidgetActions/States/ActionState.hpp"

class DefaultState : public ActionState
{
public:
    DefaultState(ActionWidget* widget, std::map<std::string, std::tuple<std::string, std::string>>* palette = new std::map<std::string, std::tuple<std::string, std::string>>{});
    virtual QColor getColour(std::string colour);
    virtual void mousePressEvent(QMouseEvent* event);
};
