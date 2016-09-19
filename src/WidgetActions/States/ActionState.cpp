#include "WidgetActions/States/ActionState.hpp"

ActionState::ActionState(ActionWidget* widget) : palette{new std::map<std::string, std::tuple<std::string, std::string>>{}}, widget{widget}, mask{new QRegion{}} {}

ActionState::ActionState(ActionState* other) : palette{other->palette}, widget{other->widget}, mask{other->mask} {}

void ActionState::changeMask(QRegion* region)
{
    delete mask;
    mask = new QRegion{*region};
}

void ActionState::changeMask(QPainterPath* path)
{
    delete mask;
    mask = new QRegion{path->toFillPolygon().toPolygon()};
}

void ActionState::mousePressEvent(QMouseEvent*) {}

void ActionState::mouseMoveEvent(QMouseEvent*) {}

void ActionState::mouseReleaseEvent(QMouseEvent*) {}

ActionState::~ActionState() {}
