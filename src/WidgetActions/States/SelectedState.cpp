#include "WidgetActions/States/SelectedState.hpp"

#include "Registry.hpp"

SelectedState::SelectedState(ActionWidget* widget, std::map<std::string, std::tuple<std::string, std::string>>* palette) : ActionState{widget, palette} {}

QColor SelectedState::getColour(std::string colour)
{
    return Registry::getRegistry()->extrinsic->GUI->palette[std::get<1>((*palette)[colour])];
}

