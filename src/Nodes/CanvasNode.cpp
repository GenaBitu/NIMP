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
        glBindTexture(GL_TEXTURE_2D, output->ID);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, data->width, data->height, 0, GL_LUMINANCE_ALPHA, GL_UNSIGNED_BYTE, data->rawData());
        return output;
    }
    // TODO: DIE HORRIBLY IN FLAMES
    return nullptr;
}
