#include "WidgetActions/States/ActionState.hpp"

ActionState::ActionState(ActionWidget* widget) : palette{new std::map<std::string, std::tuple<std::string, std::string>>{}}, widget{widget} {}

ActionState::ActionState(ActionState *other) : palette{other->palette}, widget{other->widget} {}

void ActionState::mousePressEvent(QMouseEvent*) {}

void ActionState::mouseMoveEvent(QMouseEvent*) {}

void ActionState::mouseReleaseEvent(QMouseEvent*) {}

ActionState::~ActionState() {}
