#pragma once

#include "Global.hpp"

class ActionWidget;

class ActionState
{
public:
    ActionState(ActionWidget* widget, const std::map<std::string, std::tuple<std::string, std::string>>& palette);
    virtual void mousePressEvent(QMouseEvent*);
    virtual void mouseMoveEvent(QMouseEvent*);
    virtual void mouseReleaseEvent(QMouseEvent*);
    virtual ~ActionState();
protected:
    ActionWidget* widget;
    std::map<std::string, std::tuple<std::string, std::string>> palette;
};
