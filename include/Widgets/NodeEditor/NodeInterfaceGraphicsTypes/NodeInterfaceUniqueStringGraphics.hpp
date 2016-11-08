#pragma once

#include "Global.hpp"

#include "Widgets/NodeEditor/NodeInterfaceGraphics.hpp"

class NodeInterfaceUniqueString;

class NodeInterfaceUniqueStringGraphics : public NodeInterfaceGraphics
{
    Q_OBJECT
    Q_DISABLE_COPY(NodeInterfaceUniqueStringGraphics)
public:
    NodeInterfaceUniqueStringGraphics(NodeGraphics* parent, NodeInterfaceUniqueString* interface, int y);
private:
    NodeInterfaceUniqueString* interface;
    QLineEdit* textbox;
private slots:
    void triggered();
    void valueChanged();
};
