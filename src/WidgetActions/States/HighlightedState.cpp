#include "WidgetActions/States/HighlightedState.hpp"

#include "WidgetActions/ActionWidget.hpp"
#include "Registry.hpp"

HighlightedState::HighlightedState(ActionWidget* widget) : ActionState{widget} {}

HighlightedState::HighlightedState(const ActionState& other) : ActionState{other} {}

ActionWidget::State HighlightedState::getState()
{
	return ActionWidget::State::HIGHLIGHTED;
}

QColor HighlightedState::getColour(std::string colour)
{
	return Registry::getRegistry()->extrinsic->GUI->palette[std::get<1>((*palette)[colour])];
}
