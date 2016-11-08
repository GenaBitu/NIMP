#pragma once

#include "Global.hpp"

#include "Widgets/NodeEditor/NodeInterfaceGraphics.hpp"

class NodeInterfaceString;

class NodeInterfaceStringGraphics : public NodeInterfaceGraphics
{
    Q_OBJECT
    Q_DISABLE_COPY(NodeInterfaceStringGraphics)
public:
    NodeInterfaceStringGraphics(NodeGraphics* parent, NodeInterfaceString* interface, int y);
private:
    NodeInterfaceString* interface;
    QLineEdit* textbox;
private slots:
    void triggered();
    void valueChanged();
};
