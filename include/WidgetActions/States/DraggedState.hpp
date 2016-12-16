#pragma once

#include "Global.hpp"

#include "WidgetActions/States/ActionState.hpp"

class DraggedState : public ActionState
{
public:
    DraggedState(ActionWidget* widget);
    DraggedState(const ActionState& other);
    virtual ActionWidget::State getState() override;
    virtual QColor getColour(std::string colour) override;
    virtual void mouseMoveEvent(QMouseEvent* event) override;
    virtual void mouseReleaseEvent(QMouseEvent* event) override;
};
