#include "NodeSystem/NodeInputTypes/NodeInputImage.hpp"

NodeInputImage::NodeInputImage(Node* parent, std::string name) : NodeInput(parent, name) {}

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
