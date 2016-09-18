#include "WidgetActions/States/ActionState.hpp"

ActionState::ActionState(ActionWidget* widget, std::map<std::string, std::tuple<std::string, std::string>>* palette) : palette{palette}, widget{widget} {}

void ActionState::mousePressEvent(QMouseEvent*) {}

void ActionState::mouseMoveEvent(QMouseEvent*) {}

void ActionState::mouseReleaseEvent(QMouseEvent*) {}

ActionState::~ActionState() {}
