#include "WidgetActions/ActionWidget.hpp"

#include "WidgetActions/States/DefaultState.hpp"
#include "WidgetActions/ActionWidgetContainer.hpp"

ActionWidget::ActionWidget(ActionWidgetContainer* parent) : QWidget(parent), state{new DefaultState{this}} {}

void ActionWidget::select()
{
    ActionWidgetContainer* container{dynamic_cast<ActionWidgetContainer*>(parentWidget())};
    container->select(this);
}

void ActionWidget::deselect()
{
    ActionWidgetContainer* container{dynamic_cast<ActionWidgetContainer*>(parentWidget())};
    container->deselect(this);
}

ActionWidget::~ActionWidget()
{
    deselect();
}
