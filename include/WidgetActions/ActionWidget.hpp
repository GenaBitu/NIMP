#pragma once

#include "Global.hpp"

class ActionState;

class ActionWidget : public QWidget
{
    Q_OBJECT
public:
    ActionWidget(QWidget* parent = nullptr, const std::map<std::string, std::tuple<std::string, std::string>>& palette = std::map<std::string, std::tuple<std::string, std::string>>());
    virtual void changeState(ActionState* state) = 0;
protected:
    ActionState* state;
};
