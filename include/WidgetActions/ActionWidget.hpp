#pragma once

#include "Global.hpp"

class ActionState;

class ActionWidget : public QWidget
{
    Q_OBJECT
public:
    ActionWidget(QWidget* parent = nullptr);
    virtual void changeState(ActionState* state) = 0;
protected:
    ActionState* state;
};
