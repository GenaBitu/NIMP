#include "WidgetActions/States/SelectedState.hpp"

SelectedState::SelectedState(ActionWidget* widget, const std::map<std::string, std::tuple<std::string, std::string>>& palette) : ActionState{widget, palette} {}
