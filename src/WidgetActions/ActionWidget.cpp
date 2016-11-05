#include "WidgetActions/ActionWidget.hpp"

#include "WidgetActions/States/DefaultState.hpp"
#include "WidgetActions/ActionWidgetContainer.hpp"

ActionWidget::ActionWidget(ActionWidgetContainer* parent) : QWidget(parent), state{new DefaultState{this}} {}

ActionWidget::States ActionWidget::getState()
{
    return state->getState();
}

void ActionWidget::select()
{
    ActionWidgetContainer* container{dynamic_cast<ActionWidgetContainer*>(parentWidget())};
    container->select(this);
}

void ActionWidget::deselect()
{
    ActionWidgetContainer* container{dynamic_cast<ActionWidgetContainer*>(parentWidget())};
    if(container != nullptr)
    {
        container->deselect(this);
    }
}

ActionWidget::~ActionWidget()
{
    deselect();
    delete state;
}
