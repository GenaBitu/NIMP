#include "Widgets/NodeEditor/NodeInterfaceGraphicsTypes/NodeInterfaceBoolGraphics.hpp"

#include "NodeSystem/NodeInterfaceTypes/NodeInterfaceBool.hpp"
#include "Registry.hpp"

NodeInterfaceBoolGraphics::NodeInterfaceBoolGraphics(NodeGraphics* parent, NodeInterfaceBool* interface, int y) : NodeInterfaceGraphics{parent, y}, interface{interface}
{
    QCheckBox* checkbox{new QCheckBox{QString::fromStdString(interface->name), this}};
    setStyleSheet("QCheckBox {background-color: " + Registry::getRegistry()->extrinsic->GUI->palette["NodeBackground"].name() + "; outline: 0;}");
    checkbox->installEventFilter(this);
    resize(width(), checkbox->height());
}
