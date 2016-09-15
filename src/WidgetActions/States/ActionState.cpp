#include "WidgetActions/States/ActionState.hpp"

ActionState::ActionState(ActionWidget* widget, const std::map<std::string, std::tuple<std::string, std::string>>& palette) : widget{widget}, palette{palette} {}

void ActionState::mousePressEvent(QMouseEvent*) {}

void ActionState::mouseMoveEvent(QMouseEvent*) {}

void ActionState::mouseReleaseEvent(QMouseEvent*) {}

ActionState::~ActionState() {}
