#include "WidgetActions/Draggable.hpp"

#include "WidgetActions/States/DefaultState.hpp"
#include "WidgetActions/States/DraggedState.hpp"
#include "WidgetActions/States/SelectedState.hpp"
#include "WidgetActions/ActionWidgetContainer.hpp"

Draggable::Draggable(ActionWidgetContainer* parent) : ActionWidget{parent} {}

void Draggable::changeState(States state)
{
    ActionState* oldState{this->state};
    ActionWidgetContainer* container{dynamic_cast<ActionWidgetContainer*>(parentWidget())};
    if(container == nullptr)
    {
        //TODO: DIE HORRIBLY IN FLAMES
    }
    switch(state)
    {
    case States::DEFAULT:
        this->state = new DefaultState{*oldState};
        update();
        delete oldState;
        deselect();
        break;
    case States::SELECTED:
        this->state = new SelectedState{*oldState};
        update();
        delete oldState;
        select();
        break;
    case States::DRAGGED:
        this->state = new DraggedState{*oldState};
        update();
        delete oldState;
        select();
        break;
    default:
        break;
    }
}

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
