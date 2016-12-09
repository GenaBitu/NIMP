#pragma once

#include "Global.hpp"

#include "WidgetActions/ActionWidget.hpp"

class Selectable : public ActionWidget
{
    Q_OBJECT
public:
    virtual void changeState(State state) override;
protected:
    Selectable(ActionWidgetContainer* parent = nullptr);
    virtual void mousePressEvent(QMouseEvent* event) override;
};
