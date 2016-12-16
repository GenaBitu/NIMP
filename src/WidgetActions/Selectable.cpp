#include "WidgetActions/Selectable.hpp"

#include "WidgetActions/States/DefaultState.hpp"
#include "WidgetActions/States/HighlightedState.hpp"
#include "WidgetActions/States/SelectedState.hpp"

void Selectable::changeState(State state)
{
    ActionState* oldState{this->state};
    switch(state)
    {
    case State::DEFAULT:
        this->state = new DefaultState{*oldState};
        update();
        delete oldState;
        deselect();
        break;
	case State::HIGHLIGHTED:
		this->state = new HighlightedState{*oldState};
		update();
		delete oldState;
		deselect();
		break;
    case State::SELECTED:
        this->state = new SelectedState{*oldState};
        update();
        delete oldState;
        select();
        break;
    case State::DRAGGED:
    default:
        break;
    }
}

Selectable::Selectable(ActionWidgetContainer* parent) : ActionWidget(parent) {}

void Selectable::mousePressEvent(QMouseEvent* event)
{
    state->mousePressEvent(event);
}
