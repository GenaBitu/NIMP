#pragma once

#include "Global.hpp"

#include "Widgets/NodeEditor/NodeInterfaceGraphics.hpp"

class NodeInterfaceBool;

class NodeInterfaceBoolGraphics : public NodeInterfaceGraphics
{
    Q_OBJECT
    Q_DISABLE_COPY(NodeInterfaceBoolGraphics)
public:
    NodeInterfaceBoolGraphics(NodeGraphics* parent, NodeInterfaceBool* interface, int y);
private:
    NodeInterfaceBool* interface;
    QCheckBox* checkbox;
private slots:
    void triggered(int state);
    void valueChanged();
};
