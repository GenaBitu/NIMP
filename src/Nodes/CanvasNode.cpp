#include "Nodes/CanvasNode.hpp"

#include "Texture.hpp"
#include "NodeSystem/NodeInputTypes/NodeInputImage.hpp"
#include "NodeSystem/NodeInterfaceTypes/NodeInterfaceUniqueString.hpp"
#include "Widgets/Canvas.hpp"
#include "Registry.hpp"
#include "NodeSystem/NodeNotifier.hpp"
#include "NodeSystem/NodeInterfaceNotifier.hpp"
#include "NodeSystem/NodeIONotifier.hpp"

CanvasNode::CanvasNode(int x, int y) : Node(x, y)
{
    inputs.push_back(new NodeInputImage{this, "Image"});
	NodeInterfaceUniqueString* interface{new NodeInterfaceUniqueString{this, "Display?"}};
    interfaces.push_back(interface);
	Registry::getRegistry()->intrinsic->canvases[this] = interface->getValue();
	QObject::connect(interface->notifier, &NodeInterfaceNotifier::QtValueChanged, [this]()->void{this->nameChanged();});
	emit Registry::getRegistry()->notifier->canvasesChanged();
}

std::string CanvasNode::nodeName()
{
    return "Canvas";
}

void CanvasNode::invalidateCache()
{
	notifier->imageChanged();
}

Texture* CanvasNode::getTexture()
{
    NodeDataImage* data{dynamic_cast<NodeDataImage*>(inputs[0]->getData())};
    if(data != nullptr)
    {
        Texture* output{new Texture{}};
        glBindTexture(GL_TEXTURE_2D, output->ID);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, data->width, data->height, 0, GL_RGBA, GL_FLOAT, data->rawData());
        return output;
    }
    // TODO: DIE HORRIBLY IN FLAMES
    return nullptr;
}

CanvasNode::~CanvasNode()
{
	Registry::getRegistry()->intrinsic->canvases.erase(this);
	emit Registry::getRegistry()->notifier->canvasesChanged();
}

void CanvasNode::nameChanged()
{
	NodeInterfaceUniqueString* interface{dynamic_cast<NodeInterfaceUniqueString*>(interfaces[0])};
	if(interface == nullptr)
	{
		// TODO: DIE HORRIBLY IN FLAMES
	}
	Registry::getRegistry()->intrinsic->canvases[this] = interface->getValue();
	emit Registry::getRegistry()->notifier->canvasesChanged();
}
