#include "WidgetActions/Selectable.hpp"

#include "WidgetActions/States/DefaultState.hpp"
#include "WidgetActions/States/SelectedState.hpp"

Selectable::Selectable(QWidget* parent, const std::map<std::string, std::tuple<std::string,std::string>>& palette) : ActionWidget(parent, palette) {}

void Selectable::mousePressEvent(QMouseEvent* event)
{
    state->mousePressEvent(event);
}

void Selectable::changeState(ActionState* state)
{
    DefaultState* defState{dynamic_cast<DefaultState*>(state)};
    if(defState != nullptr)
    {
        delete this->state;
        this->state = defState;
        return;
    }
    SelectedState* selState{dynamic_cast<SelectedState*>(state)};
    if(selState != nullptr)
    {
        delete this->state;
        this->state = selState;
        return;
    }
    return;
}
