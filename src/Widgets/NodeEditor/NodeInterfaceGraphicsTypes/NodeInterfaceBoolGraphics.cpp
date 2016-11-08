#include "Widgets/NodeEditor/NodeInterfaceGraphicsTypes/NodeInterfaceBoolGraphics.hpp"

#include "NodeSystem/NodeInterfaceTypes/NodeInterfaceBool.hpp"
#include "Registry.hpp"

NodeInterfaceBoolGraphics::NodeInterfaceBoolGraphics(NodeGraphics* parent, NodeInterfaceBool* interface, int y) : NodeInterfaceGraphics{parent, y}, interface{interface}, checkbox{new QCheckBox{QString::fromStdString(interface->name), this}}
{
    valueChanged();
    checkbox->setStyleSheet("QCheckBox {background-color: " + Registry::getRegistry()->extrinsic->GUI->palette["NodeBackground"].name() + "; outline: 0;}");
    checkbox->installEventFilter(this);
    resize(width(), checkbox->height());
    show();
    QObject::connect(checkbox, &QCheckBox::stateChanged, this, &NodeInterfaceBoolGraphics::triggered);
    QObject::connect(interface, &NodeInterfaceBool::valueChanged, this, &NodeInterfaceBoolGraphics::valueChanged);
}

void NodeInterfaceBoolGraphics::triggered(int state)
{
    interface->setValue(state);
}

void NodeInterfaceBoolGraphics::valueChanged()
{
    checkbox->setChecked(interface->getValue());
}
