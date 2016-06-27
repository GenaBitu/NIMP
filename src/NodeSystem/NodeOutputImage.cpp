#include "include/NodeSystem/NodeOutputImage.hpp"

NodeOutputImage::NodeOutputImage(Node* parent) : NodeOutput(parent) {}

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
