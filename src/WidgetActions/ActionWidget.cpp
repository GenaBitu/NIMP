#include "WidgetActions/ActionWidget.hpp"

#include "WidgetActions/States/DefaultState.hpp"

ActionWidget::ActionWidget(QWidget* parent) : QWidget(parent), state{new DefaultState{this}} {}
