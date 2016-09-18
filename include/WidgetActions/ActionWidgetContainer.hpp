#pragma once

#include "Global.hpp"

class ActionWidget;

class ActionWidgetContainer : public QWidget
{
    Q_OBJECT
public:
    virtual void select(ActionWidget* widget);
protected:
    ActionWidgetContainer(QWidget* parent = nullptr);
    ActionWidget* selected;
};
