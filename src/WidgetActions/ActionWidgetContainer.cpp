#include "WidgetActions/ActionWidgetContainer.hpp"

#include "WidgetActions/ActionWidget.hpp"

ActionWidgetContainer::ActionWidgetContainer(QWidget* parent) : QWidget{parent}, selected{} {}

void ActionWidgetContainer::select(ActionWidget* widget)
{
    if(selected != nullptr and selected != widget)
    {
        selected->changeState(ActionWidget::States::DEFAULT);
    }
    selected = widget;
}
