#include "include/NodeSystem/NodeInputInt.hpp"

NodeInputInt::NodeInputInt(Node* parent, std::string name) : NodeInput{parent, name} {}

NodeDataInt* NodeInputInt::getData()
{
    NodeDataInt* intData{dynamic_cast<NodeDataInt*>(NodeInput::getData())};
    if(intData != nullptr)
    {
        return intData;
    }
    // TODO: DIE HORRIBLY IN FLAMES
    return nullptr;
}
