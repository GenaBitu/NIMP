#include "WidgetActions/States/SelectedState.hpp"

#include "Registry.hpp"
#include "WidgetActions/ActionWidget.hpp"

SelectedState::SelectedState(ActionWidget* widget) : ActionState{widget} {}

SelectedState::SelectedState(ActionState* other) : ActionState{other} {}

QColor SelectedState::getColour(std::string colour)
{
    return Registry::getRegistry()->extrinsic->GUI->palette[std::get<1>((*palette)[colour])];
}

void SelectedState::mousePressEvent(QMouseEvent* event)
{
    if((mask->isEmpty() or mask->contains(event->pos())) and (event->button() == Qt::LeftButton))
    {
        event->accept();
        *origin = event->globalPos() - widget->pos();
    }
    else
    {
        event->ignore();
    }
}

void SelectedState::mouseMoveEvent(QMouseEvent* event)
{
    if(((event->globalPos() - widget->pos() - *origin).manhattanLength() > 10) and *origin != QPoint{})
    {
        widget->changeState(ActionWidget::States::DRAGGED);
    }
}
