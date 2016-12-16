#pragma once

#include "Global.hpp"

class ActionState;
class ActionWidgetContainer;

class ActionWidget : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(ActionWidget)
public:
    enum class State{DEFAULT, HIGHLIGHTED, SELECTED, DRAGGED};
    ActionWidget(ActionWidgetContainer* parent = nullptr);
    virtual State getState();
    virtual void changeState(State state) = 0;
    void select();
    void deselect();
    virtual ~ActionWidget();
protected:
    ActionState* state;
};
