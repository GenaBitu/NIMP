#pragma once

#include "Global.hpp"

#include "WidgetActions/ActionWidget.hpp"

class Selectable : public ActionWidget
{
    Q_OBJECT
public:
    virtual void changeState(States state);
protected:
    Selectable(ActionWidgetContainer* parent = nullptr);
    virtual void mousePressEvent(QMouseEvent* event);
};
