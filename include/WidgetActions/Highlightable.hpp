#pragma once

#include "Global.hpp"

#include "WidgetActions/ActionWidget.hpp"

class Highlightable : public ActionWidget
{
	Q_OBJECT
public:
	virtual void changeState(State state) override;
protected:
	Highlightable(ActionWidgetContainer* parent = nullptr);
};
