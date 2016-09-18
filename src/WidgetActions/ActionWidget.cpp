#include "WidgetActions/ActionWidget.hpp"

#include "WidgetActions/States/DefaultState.hpp"
#include "WidgetActions/ActionWidgetContainer.hpp"

ActionWidget::ActionWidget(ActionWidgetContainer* parent) : QWidget(parent), state{new DefaultState{this}} {}
