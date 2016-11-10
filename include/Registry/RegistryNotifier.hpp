#pragma once

#include "Global.hpp"

class Node;
class Registry;

class RegistryNotifier : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(RegistryNotifier)
private:
    friend Registry;
    RegistryNotifier();
signals:
    void nodeAdded(Node*);
	void canvasesChanged();
};
