#pragma once

#include "Global.hpp"

#include "WidgetActions/ActionWidget.hpp"

class Draggable : public ActionWidget
{
    Q_OBJECT
public:
    virtual void changeState(States state) override;
protected:
    Draggable(ActionWidgetContainer* parent = nullptr);
    virtual void mousePressEvent(QMouseEvent* event) override;
    virtual void mouseMoveEvent(QMouseEvent* event) override;
    virtual void mouseReleaseEvent(QMouseEvent* event) override;
};
