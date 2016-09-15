#include "WidgetActions/ActionWidget.hpp"

#include "WidgetActions/States/DefaultState.hpp"

ActionWidget::ActionWidget(QWidget* parent, const std::map<std::string, std::tuple<std::string, std::string>>& palette) : QWidget(parent), state{new DefaultState{this, palette}} {}
