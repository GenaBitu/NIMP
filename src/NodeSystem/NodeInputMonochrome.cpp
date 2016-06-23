#include "include/NodeSystem/NodeInputMonochrome.hpp"

#include "include/NodeSystem/NodeOutputMonochrome.hpp"

NodeInputMonochrome::NodeInputMonochrome(Node* parent) : NodeInput(parent) {}

NodeDataMonochrome* NodeInputMonochrome::getData()
{
    NodeOutputMonochrome* rawConnection{dynamic_cast<NodeOutputMonochrome*>(connection)};
    if(rawConnection != nullptr)
    {
        return rawConnection->getData();
    }
    // TODO: DIE HORRIBLY IN FLAMES
    return nullptr;
}
