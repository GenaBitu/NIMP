#pragma once

#include "Global.hpp"

#include "WidgetActions/ActionWidget.hpp"

class Selectable : public ActionWidget
{
protected:
    Selectable(QWidget* parent = nullptr);
    virtual void mousePressEvent(QMouseEvent* event);
private:
    virtual void changeState(ActionState* state);
};
