#pragma once

#include "Global.hpp"

#include "WidgetActions/ActionWidget.hpp"

class ActionState
{
public:
    std::map<std::string, std::tuple<std::string, std::string>>* palette;
    ActionState(ActionWidget* widget);
    ActionState(const ActionState& other);
    ActionState(ActionState&& other);
    ActionState& operator=(const ActionState& other) = delete;
    friend void swap(ActionState& first, ActionState& second);
    virtual ActionWidget::State getState() = 0;
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
