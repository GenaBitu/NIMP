#pragma once

#include "Global.hpp"

class ActionWidget;

class ActionState
{
public:
    std::map<std::string, std::tuple<std::string, std::string>>* palette;
    ActionState(ActionWidget* widget);
    ActionState(const ActionState& other);
    ActionState(ActionState&& other);
    ActionState& operator=(ActionState other);
    friend void swap(ActionState& first, ActionState& second);
    virtual QColor getColour(std::string colour);
    virtual void changeMask(QRegion* region);
    virtual void changeMask(QPainterPath* path);
    virtual void mousePressEvent(QMouseEvent*);
    virtual void mouseMoveEvent(QMouseEvent*);
    virtual void mouseReleaseEvent(QMouseEvent*);
    virtual ~ActionState();
protected:
    ActionWidget* widget;
    QRegion* mask;
    QPoint* origin;
private:
    ActionState();
};
