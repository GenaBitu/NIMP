#pragma once

#include "Global.hpp"

#include "WidgetActions/States/ActionState.hpp"

class SelectedState : public ActionState
{
public:
    SelectedState(ActionWidget* widget, std::map<std::string, std::tuple<std::string, std::string>>* palette = new std::map<std::string, std::tuple<std::string, std::string>>{});
    virtual QColor getColour(std::string colour);
};
