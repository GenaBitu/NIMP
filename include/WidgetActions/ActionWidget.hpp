#pragma once

#include "Global.hpp"

class ActionState;

class ActionWidget : public QWidget
{
    Q_OBJECT
public:
    ActionWidget();
protected:
    ActionState* state;
private:
    friend ActionState;
    virtual void changeState(ActionState* state) = 0;
};
