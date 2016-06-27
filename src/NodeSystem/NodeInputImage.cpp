#include "include/NodeSystem/NodeInputImage.hpp"

NodeInputImage::NodeInputImage(Node* parent) : NodeInput(parent) {}

NodeDataImage* NodeInputImage::getData()
{
    NodeDataImage* imageData{dynamic_cast<NodeDataImage*>(NodeInput::getData())};
    if(imageData != nullptr)
    {
        return imageData;
    }
    // TODO: DIE HORRIBLY IN FLAMES
    return nullptr;
}
