#include "include/NodeSystem/NodeInputMonochrome.hpp"

NodeInputMonochrome::NodeInputMonochrome(Node* parent) : NodeInput(parent) {}

NodeDataMonochrome* NodeInputMonochrome::getData()
{
    NodeDataMonochrome* monochromeData{dynamic_cast<NodeDataMonochrome*>(NodeInput::getData())};
    if(monochromeData != nullptr)
    {
        return monochromeData;
    }
    // TODO: DIE HORRIBLY IN FLAMES
    return nullptr;
}
