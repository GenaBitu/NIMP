#include "NodeSystem/NodeOutputTypes/NodeOutputImage.hpp"

NodeOutputImage::NodeOutputImage(Node* parent, std::string name) : NodeOutput(parent, name) {}

NodeDataImage* NodeOutputImage::getData()
{
    NodeDataImage* imageData{dynamic_cast<NodeDataImage*>(NodeOutput::getData())};
    if(imageData != nullptr)
    {
        return imageData;
    }
    // TODO: DIE HORRIBLY IN FLAMES
    return nullptr;
}
