#include "WidgetActions/States/DefaultState.hpp"

#include "Registry.hpp"
#include "WidgetActions/ActionWidget.hpp"
#include "WidgetActions/States/SelectedState.hpp"

DefaultState::DefaultState(ActionWidget* widget) : ActionState{widget} {}

DefaultState::DefaultState(const ActionState& other) : ActionState{other} {}

void DefaultState::mousePressEvent(QMouseEvent* event)
{
    if((mask->isEmpty() or mask->contains(event->pos())) and (event->button() == Qt::LeftButton))
    {
        event->accept();
        *origin = event->globalPos() - widget->pos();
        widget->raise();
        widget->changeState(ActionWidget::States::SELECTED);
    }
    else
    {
        event->ignore();
    }
}
