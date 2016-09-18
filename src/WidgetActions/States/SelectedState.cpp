#include "WidgetActions/States/SelectedState.hpp"

#include "Registry.hpp"

SelectedState::SelectedState(ActionWidget* widget) : ActionState{widget} {}

SelectedState::SelectedState(ActionState* other) : ActionState{other} {}

QColor SelectedState::getColour(std::string colour)
{
    return Registry::getRegistry()->extrinsic->GUI->palette[std::get<1>((*palette)[colour])];
}

