#include "WidgetActions/States/DraggedState.hpp"

#include "Registry.hpp"
#include "WidgetActions/ActionWidget.hpp"

DraggedState::DraggedState(ActionWidget* widget) : ActionState{widget} {}

DraggedState::DraggedState(const ActionState& other) : ActionState{other} {}

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
    *origin = QPoint{};
    widget->changeState(ActionWidget::States::SELECTED);
}
