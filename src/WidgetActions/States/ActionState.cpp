#include "WidgetActions/States/ActionState.hpp"

#include "WidgetActions/ActionWidget.hpp"
#include "Registry.hpp"

ActionState::ActionState(ActionWidget* widget) : palette{new std::map<std::string, std::tuple<std::string, std::string>>{}}, widget{widget}, mask{new QRegion{}}, origin{new QPoint{}} {}

ActionState::ActionState(const ActionState& other) : palette{other.palette->size() ? new std::map<std::string, std::tuple<std::string, std::string>>{} : nullptr}, widget{other.widget}, mask{new QRegion{*(other.mask)}}, origin{new QPoint{*(other.origin)}}
{
    if(palette != nullptr)
    {
        palette->insert(other.palette->begin(), other.palette->end());
    }
}

ActionState::ActionState(ActionState&& other) : ActionState{}
{
    swap(*this, other);
}

void swap(ActionState& first, ActionState& second)
{
    using std::swap;
    swap(first.palette, second.palette);
    swap(first.widget, second.widget);
    swap(first.mask, second.mask);
    swap(first.origin, second.origin);
}

QColor ActionState::getColour(std::string colour)
{
    return Registry::getRegistry()->extrinsic->GUI->palette[std::get<0>((*palette)[colour])];
}

void ActionState::setMask(QRegion* region)
{
    delete mask;
    mask = new QRegion{*region};
}

void ActionState::setMask(QPainterPath* path)
{
    delete mask;
    mask = new QRegion{path->toFillPolygon().toPolygon()};
}

QRegion* ActionState::getMask()
{
	return new QRegion{*mask};
}

void ActionState::mousePressEvent(QMouseEvent*) {}

void ActionState::mouseMoveEvent(QMouseEvent*) {}

void ActionState::mouseReleaseEvent(QMouseEvent*) {}

ActionState::~ActionState()
{
    delete palette;
    delete mask;
    delete origin;
}

ActionState::ActionState() : palette{}, widget{}, mask{}, origin{} {}
