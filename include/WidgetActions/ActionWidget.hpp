#pragma once

#include "Global.hpp"

class ActionWidget : public QWidget
{
    Q_OBJECT
protected:
    #include "WidgetActions/ActionWidget/ActionState.hpp"
    #include "WidgetActions/ActionWidget/DefaultState.hpp"
    #include "WidgetActions/ActionWidget/SelectedState.hpp"
public:
    ActionWidget(QWidget* parent = 0);
protected:
    ActionState* state;
private:
    friend ActionState;
    virtual void changeState(ActionState* state) = 0;
};
