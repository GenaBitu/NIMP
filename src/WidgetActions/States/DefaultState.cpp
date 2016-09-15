#include "WidgetActions/States/DefaultState.hpp"

#include "WidgetActions/ActionWidget.hpp"
#include "WidgetActions/States/SelectedState.hpp"

DefaultState::DefaultState(ActionWidget* widget, const std::map<std::string, std::tuple<std::string, std::string>>& palette) : ActionState{widget, palette} {}

void DefaultState::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        widget->changeState(new SelectedState{widget, palette});
    }
}
