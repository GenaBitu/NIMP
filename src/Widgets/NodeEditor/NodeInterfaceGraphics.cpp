#include "Widgets/NodeEditor/NodeInterfaceGraphics.hpp"

#include "Widgets/NodeEditor/NodeGraphics.hpp"
#include "Registry.hpp"
#include "NodeSystem/NodeInterfaceTypes.hpp"
#include "Widgets/NodeEditor/NodeInterfaceGraphicsTypes.hpp"

NodeInterfaceGraphics::NodeInterfaceGraphics(NodeGraphics* parent, int y) : QWidget(parent)
{
    resize(parent->width(), height());
    move(Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"] , y);
}

NodeInterfaceGraphics* NodeInterfaceGraphics::interfaceFactory(NodeGraphics* parent, NodeInterface* interface, int y)
{
    NodeInterfaceBool* boolInterface{dynamic_cast<NodeInterfaceBool*>(interface)};
    if(boolInterface != nullptr)
    {
        return new NodeInterfaceBoolGraphics{parent, boolInterface, y};
    }
    else
    {
        // TODO: DIE HORRIBLY IN FLAMES
        return nullptr;
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
