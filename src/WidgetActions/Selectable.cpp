#include "WidgetActions/Selectable.hpp"

#include "WidgetActions/States/DefaultState.hpp"
#include "WidgetActions/States/SelectedState.hpp"
#include "WidgetActions/ActionWidgetContainer.hpp"

void Selectable::changeState(States state)
{
    ActionState* oldState{this->state};
    ActionWidgetContainer* container{dynamic_cast<ActionWidgetContainer*>(parentWidget())};
    if(container == nullptr)
    {
        // TODO: DIE HORRIBLY IN FLAMES
        return;
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
    default:
        break;
    }
}

Selectable::Selectable(ActionWidgetContainer* parent) : ActionWidget(parent) {}

void Selectable::mousePressEvent(QMouseEvent* event)
{
    state->mousePressEvent(event);
}
