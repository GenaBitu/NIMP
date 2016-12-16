#pragma once

#include "Global.hpp"

#include "WidgetActions/States/ActionState.hpp"

class HighlightedState : public ActionState
{
public:
	HighlightedState(ActionWidget* widget);
	HighlightedState(const ActionState& other);
	virtual ActionWidget::State getState() override;
	virtual QColor getColour(std::string colour) override;
};
