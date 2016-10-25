#pragma once

#include "Global.hpp"

#include "WidgetActions/ActionWidget.hpp"

class Selectable : public ActionWidget
{
    Q_OBJECT
protected:
    Selectable(ActionWidgetContainer* parent = nullptr);
    virtual void changeState(States state);
    virtual void mousePressEvent(QMouseEvent* event);
};
