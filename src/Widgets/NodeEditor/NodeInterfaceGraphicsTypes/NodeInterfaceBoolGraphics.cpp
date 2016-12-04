#include "Widgets/NodeEditor/NodeInterfaceGraphicsTypes/NodeInterfaceBoolGraphics.hpp"

#include "NodeSystem/NodeInterfaceTypes/NodeInterfaceBool.hpp"
#include "Registry.hpp"
#include "NodeSystem/NodeInterfaceNotifier.hpp"

NodeInterfaceBoolGraphics::NodeInterfaceBoolGraphics(NodeGraphics* parent, NodeInterfaceBool* interface, int y) : NodeInterfaceGraphics{parent, y}, interface{interface}, checkbox{new QCheckBox{QString::fromStdString(interface->name), this}}
{
    valueChanged();
    checkbox->setStyleSheet(QString::fromStdString(Registry::getRegistry()->extrinsic->GUI->stylesheets["NodeInterfaceBoolGraphics"]));
    checkbox->installEventFilter(this);
    resize(width(), checkbox->height());
    show();
    QObject::connect(checkbox, &QCheckBox::stateChanged, this, &NodeInterfaceBoolGraphics::triggered);
    QObject::connect(interface->notifier, &NodeInterfaceNotifier::QtValueChanged, this, &NodeInterfaceBoolGraphics::valueChanged);
}

void NodeInterfaceBoolGraphics::triggered(int state)
{
    interface->setValue(state);
}

void NodeInterfaceBoolGraphics::valueChanged()
{
    checkbox->setChecked(interface->getValue());
}
