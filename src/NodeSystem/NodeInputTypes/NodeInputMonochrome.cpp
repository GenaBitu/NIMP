#include "NodeSystem/NodeInputTypes/NodeInputMonochrome.hpp"

NodeInputMonochrome::NodeInputMonochrome(Node* parent, std::string name) : NodeInput(parent, name) {}

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
