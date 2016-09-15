#pragma once

#include "Global.hpp"

#include "WidgetActions/States/ActionState.hpp"

class SelectedState : public ActionState
{
public:
    SelectedState(ActionWidget* widget, const std::map<std::string, std::tuple<std::string, std::string>>& palette);
};
