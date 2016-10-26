#pragma once

#include "Global.hpp"

class ActionState;
class ActionWidgetContainer;

class ActionWidget : public QWidget
{
    Q_OBJECT
public:
    enum class States{DEFAULT, SELECTED, DRAGGED};
    ActionWidget(ActionWidgetContainer* parent = nullptr);
    virtual void changeState(States state) = 0;
    void select();
    void deselect();
    virtual ~ActionWidget();
protected:
    ActionState* state;
};
