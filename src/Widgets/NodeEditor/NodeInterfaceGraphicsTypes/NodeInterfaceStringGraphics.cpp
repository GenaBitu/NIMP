#include "Widgets/NodeEditor/NodeInterfaceGraphicsTypes/NodeInterfaceStringGraphics.hpp"

#include "NodeSystem/NodeInterfaceTypes/NodeInterfaceString.hpp"
#include "Registry.hpp"

NodeInterfaceStringGraphics::NodeInterfaceStringGraphics(NodeGraphics* parent, NodeInterfaceString* interface, int y) : NodeInterfaceGraphics{parent, y}, interface{interface}, textbox{new QLineEdit{QString::fromStdString(interface->getValue()), this}}
{
    textbox->setStyleSheet(QString::fromStdString(Registry::getRegistry()->extrinsic->GUI->stylesheets["NodeInterfaceStringGraphics"]));
    textbox->installEventFilter(this);
    resize(width(), textbox->height());
    show();
    QObject::connect(textbox, &QLineEdit::editingFinished, this, &NodeInterfaceStringGraphics::triggered);
    QObject::connect(interface->notifier, &NodeInterfaceNotifier::QtValueChanged, this, &NodeInterfaceStringGraphics::valueChanged);
}

void NodeInterfaceStringGraphics::triggered()
{
    interface->setValue(textbox->text().toStdString());
}

void NodeInterfaceStringGraphics::valueChanged()
{
    textbox->setText(QString::fromStdString(interface->getValue()));
}
