#include "WidgetActions/ActionWidgetContainer.hpp"

#include "WidgetActions/ActionWidget.hpp"

ActionWidgetContainer::ActionWidgetContainer(QWidget* parent) : QWidget{parent}, selected{} {}

void ActionWidgetContainer::select(ActionWidget* widget)
{
    if(selected != nullptr and selected != widget)
    {
        selected->changeState(ActionWidget::State::DEFAULT);
    }
    selected = widget;
}

void ActionWidgetContainer::deselect(ActionWidget* widget)
{
    if(selected == widget)
    {
        selected = nullptr;
    }
}
