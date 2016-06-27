#include "include/NodeSystem/NodeOutputMonochrome.hpp"

NodeOutputMonochrome::NodeOutputMonochrome(Node* parent) : NodeOutput(parent) {}

NodeDataMonochrome* NodeOutputMonochrome::getData()
{
    NodeDataMonochrome* monochromeData{dynamic_cast<NodeDataMonochrome*>(NodeOutput::getData())};
    if(monochromeData != nullptr)
    {
        return monochromeData;
    }
    // TODO: DIE HORRIBLY IN FLAMES
    return nullptr;
}
