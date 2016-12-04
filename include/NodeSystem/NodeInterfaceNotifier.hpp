#pragma once

#include "Global.hpp"

class NodeInterfaceNotifier : public QObject
{
	Q_OBJECT
public:
	void valueChanged() const;
	signals:
	void QtValueChanged() const;
};
