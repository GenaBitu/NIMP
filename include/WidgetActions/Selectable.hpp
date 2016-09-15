#pragma once

#include "Global.hpp"

#include "WidgetActions/ActionWidget.hpp"

class Selectable : public ActionWidget
{
protected:
    Selectable(QWidget* parent = nullptr, const std::map<std::string, std::tuple<std::string, std::string>>& palette = std::map<std::string, std::tuple<std::string, std::string>>());
    virtual void mousePressEvent(QMouseEvent* event);
private:
    virtual void changeState(ActionState* state);
};
