#include "Widgets/NodeEditor/NodeInterfaceGraphics.hpp"

#include "Widgets/NodeEditor/NodeGraphics.hpp"
#include "NodeSystem/NodeInterfaceTypes.hpp"
#include "Registry.hpp"

NodeInterfaceGraphics::NodeInterfaceGraphics(NodeGraphics* parent, NodeInterface* interface, int y) : QWidget(parent)
{
    resize(parent->width(), height());
    move(Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"] , y);
    show();
    NodeInterfaceBool* boolInterface{dynamic_cast<NodeInterfaceBool*>(interface)};
    if(boolInterface != nullptr)
    {
        QCheckBox* checkbox{new QCheckBox{QString::fromStdString(interface->name), this}};
        setStyleSheet("QCheckBox {background-color: " + Registry::getRegistry()->extrinsic->GUI->palette["NodeBackground"].name() + "; outline: 0;}");
        checkbox->installEventFilter(this);
        resize(width(), checkbox->height());
    }
}

bool NodeInterfaceGraphics::eventFilter(QObject*, QEvent* event)
{
    if(event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent* mouseEvent{static_cast<QMouseEvent*>(event)};
        if(mouseEvent->button() == Qt::LeftButton)
        {
            NodeGraphics* parent{dynamic_cast<NodeGraphics*>(parentWidget())};
            parent->changeState(ActionWidget::States::SELECTED);
        }
    }
    return false;
}
