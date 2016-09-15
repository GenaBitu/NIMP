#include "NodeSystem/NodeOutputTypes/NodeOutputInt.hpp"

NodeOutputInt::NodeOutputInt(Node* parent, std::string name) : NodeOutput(parent, name) {}

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
