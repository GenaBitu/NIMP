#pragma once

#include "Global.hpp"

class ActionState;
class ActionWidgetContainer;

class ActionWidget : public QWidget
{
    Q_OBJECT
public:
    enum class States{DEFAULT, SELECTED};
    ActionWidget(ActionWidgetContainer* parent = nullptr);
    virtual void changeState(States state) = 0;
protected:
    ActionState* state;
};
