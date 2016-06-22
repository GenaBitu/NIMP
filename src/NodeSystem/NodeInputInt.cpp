#include "include/NodeSystem/NodeInputInt.hpp"

#include "include/NodeSystem/NodeOutputInt.hpp"

NodeInputInt::NodeInputInt(Node* parent) : NodeInput{parent}
{

}

NodeDataInt* NodeInputInt::getData()
{
    NodeOutputInt* intConnection{dynamic_cast<NodeOutputInt*>(connection)};
    if(intConnection != nullptr)
    {
        return intConnection->getData();
    }
    // TODO: DIE HORRIBLY IN FLAMES
    return nullptr;
}
