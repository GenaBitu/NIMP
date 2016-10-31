#pragma once

#include "Global.hpp"

class ActionWidget;

class ActionWidgetContainer : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(ActionWidgetContainer)
protected:
    ActionWidget* selected;
    ActionWidgetContainer(QWidget* parent = nullptr);
private:
    friend ActionWidget;
    virtual void select(ActionWidget* widget);
    virtual void deselect(ActionWidget* widget);
};
