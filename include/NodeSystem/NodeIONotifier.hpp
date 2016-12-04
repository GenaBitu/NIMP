#pragma once

#include "Global.hpp"

class NodeIONotifier : public QObject
{
	Q_OBJECT
public:
	void reconnected() const;
signals:
	void QtReconnected() const;
};
