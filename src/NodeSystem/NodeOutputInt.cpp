#include "include/NodeSystem/NodeOutputInt.hpp"

NodeOutputInt::NodeOutputInt(Node* parent) : NodeOutput(parent) {}

NodeDataInt* NodeOutputInt::getData()
{
    NodeDataInt* intData{dynamic_cast<NodeDataInt*>(NodeOutput::getData())};
    if(intData != nullptr)
    {
        return intData;
    }
    // TODO: DIE HORRIBLY IN FLAMES
    return nullptr;
}
