#include "WidgetActions/ActionWidget.hpp"

#include "WidgetActions/States/DefaultState.hpp"
#include "WidgetActions/ActionWidgetContainer.hpp"

ActionWidget::ActionWidget(ActionWidgetContainer* parent) : QWidget(parent), state{new DefaultState{this}} {}

ActionWidget::State ActionWidget::getState()
{
    return state->getState();
}

void ActionWidget::select()
{
    ActionWidgetContainer* container{dynamic_cast<ActionWidgetContainer*>(parentWidget())};
    if(container != nullptr)
    {
        container->select(this);
    }
    else
    {
        // TODO: DIE HORRIBLY IN FLAMES
    }
}

void ActionWidget::deselect()
{
    ActionWidgetContainer* container{dynamic_cast<ActionWidgetContainer*>(parentWidget())};
    if(container != nullptr)
    {
        container->deselect(this);
    }
    else
    {
        // TODO: DIE HORRIBLY IN FLAMES
    }
}

ActionWidget::~ActionWidget()
{
    deselect();
    delete state;
}
