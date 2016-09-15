#pragma once

#include "Global.hpp"

#include "WidgetActions/ActionWidget.hpp"

class Selectable : public ActionWidget
{
public:
    Selectable();
private:
    virtual void changeState(ActionState* state) = 0;
};
