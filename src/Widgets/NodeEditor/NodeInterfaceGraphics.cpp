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
    NodeInterfaceString* stringInterface{dynamic_cast<NodeInterfaceString*>(interface)};
    NodeInterfaceUniqueString* uniqueStringInterface{dynamic_cast<NodeInterfaceUniqueString*>(interface)};
    if(boolInterface != nullptr)
    {
        return new NodeInterfaceBoolGraphics{parent, boolInterface, y};
    }
    else if(stringInterface != nullptr)
    {
        return new NodeInterfaceStringGraphics{parent, stringInterface, y};
    }
    else if(uniqueStringInterface != nullptr)
    {
        return new NodeInterfaceUniqueStringGraphics{parent, uniqueStringInterface, y};
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
            if(parent != nullptr)
			{
				parent->changeState(ActionWidget::State::SELECTED);
			}
			else
			{
				// TODO: DIE HORRIBLY IN FLAMES
			}
        }
    }
    return false;
}
