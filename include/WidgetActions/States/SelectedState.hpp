#pragma once

#include "Global.hpp"

#include "WidgetActions/States/ActionState.hpp"

class SelectedState : public ActionState
{
public:
    SelectedState(ActionWidget* widget);
    SelectedState(const ActionState& other);
    ActionWidget::State getState() override;
    virtual QColor getColour(std::string colour) override;
    virtual void mousePressEvent(QMouseEvent* event) override;
    virtual void mouseMoveEvent(QMouseEvent* event) override;
};
