#pragma once

#include "Global.hpp"

class ActionWidget;
class Draggable;
class Selectable;

class ActionWidgetContainer : public QWidget
{
    Q_OBJECT
protected:
    ActionWidget* selected;
    ActionWidgetContainer(QWidget* parent = nullptr);
private:
    friend Draggable;
    friend Selectable;
    virtual void select(ActionWidget* widget);
};
