#include "WidgetActions/States/DefaultState.hpp"

#include "Registry.hpp"
#include "WidgetActions/ActionWidget.hpp"
#include "WidgetActions/States/SelectedState.hpp"

DefaultState::DefaultState(ActionWidget* widget, std::map<std::string, std::tuple<std::string, std::string>>* palette) : ActionState{widget, palette} {}

QColor DefaultState::getColour(std::string colour)
{
    return Registry::getRegistry()->extrinsic->GUI->palette[std::get<0>((*palette)[colour])];
}

void DefaultState::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        widget->changeState(new SelectedState{widget, palette});
    }
}
