#include "WidgetActions/States/DraggedState.hpp"

#include "Registry.hpp"
#include "WidgetActions/ActionWidget.hpp"

DraggedState::DraggedState(ActionWidget* widget) : ActionState{widget} {}

DraggedState::DraggedState(ActionState* other) : ActionState{other} {}

QColor DraggedState::getColour(std::string colour)
{
    return Registry::getRegistry()->extrinsic->GUI->palette[std::get<1>((*palette)[colour])];
}

void DraggedState::mouseMoveEvent(QMouseEvent* event)
{
    widget->move(event->globalPos() - *origin);
}

void DraggedState::mouseReleaseEvent(QMouseEvent* event)
{
    widget->move(event->globalPos() - *origin);
    widget->changeState(ActionWidget::States::SELECTED);
}
