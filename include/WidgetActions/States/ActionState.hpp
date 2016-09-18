#pragma once

#include "Global.hpp"

class ActionWidget;

class ActionState
{
public:
    std::map<std::string, std::tuple<std::string, std::string>>* palette;
    ActionState(ActionWidget* widget);
    ActionState(ActionState* other);
    virtual QColor getColour(std::string colour) = 0;
    virtual void mousePressEvent(QMouseEvent*);
    virtual void mouseMoveEvent(QMouseEvent*);
    virtual void mouseReleaseEvent(QMouseEvent*);
    virtual ~ActionState();
protected:
    ActionWidget* widget;
};
