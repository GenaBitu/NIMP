#include "include/NodeSystem/NodeInputInt.hpp"

#include "include/NodeSystem/NodeOutputInt.hpp"

NodeInputInt::NodeInputInt(Node* parent) : NodeInput{parent} {}

NodeDataInt* NodeInputInt::getData()
{
    NodeOutputInt* rawConnection{dynamic_cast<NodeOutputInt*>(connection)};
    if(rawConnection != nullptr)
    {
        return rawConnection->getData();
    }
    // TODO: DIE HORRIBLY IN FLAMES
    return nullptr;
}
