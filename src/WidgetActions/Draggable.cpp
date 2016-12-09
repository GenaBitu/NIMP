#include "WidgetActions/Draggable.hpp"

#include "WidgetActions/States/DefaultState.hpp"
#include "WidgetActions/States/DraggedState.hpp"
#include "WidgetActions/States/SelectedState.hpp"
#include "WidgetActions/ActionWidgetContainer.hpp"

void Draggable::changeState(State state)
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
    case State::SELECTED:
        this->state = new SelectedState{*oldState};
        update();
        delete oldState;
        select();
        break;
    case State::DRAGGED:
        this->state = new DraggedState{*oldState};
        update();
        delete oldState;
        select();
        break;
    default:
        break;
    }
}

Draggable::Draggable(ActionWidgetContainer* parent) : ActionWidget{parent} {}

void Draggable::mousePressEvent(QMouseEvent* event)
{
    state->mousePressEvent(event);
}

void Draggable::mouseMoveEvent(QMouseEvent* event)
{
    state->mouseMoveEvent(event);
}

void Draggable::mouseReleaseEvent(QMouseEvent* event)
{
    state->mouseReleaseEvent(event);
}
