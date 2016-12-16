#include "WidgetActions/Highlightable.hpp"

#include "WidgetActions/States/DefaultState.hpp"
#include "WidgetActions/States/HighlightedState.hpp"

void Highlightable::changeState(State state)
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
    case State::DRAGGED:
    default:
        break;
    }
}

Highlightable::Highlightable(ActionWidgetContainer* parent) : ActionWidget{parent} {}
