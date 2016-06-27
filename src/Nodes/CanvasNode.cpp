#include "include/Nodes/CanvasNode.hpp"

#include "include/Texture.hpp"
#include "include/NodeSystem/NodeInputMonochrome.hpp"

CanvasNode::CanvasNode()
{
    inputs.push_back(new NodeInputMonochrome{this});
}

Texture* CanvasNode::getTexture()
{
    NodeDataMonochrome* data{dynamic_cast<NodeDataMonochrome*>(inputs[0]->getData())};
    if(data != nullptr)
    {
        Texture* output{new Texture{}};
        output->loadByteArray(data->width, data->height, data->data());
        return output;
    }
    // TODO: DIE HORRIBLY IN FLAMES
    return nullptr;
}
