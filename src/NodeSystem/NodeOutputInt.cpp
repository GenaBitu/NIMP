#include "include/NodeSystem/NodeOutputInt.hpp"

#include "include/NodeSystem/Node.hpp"

NodeOutputInt::NodeOutputInt(Node* parent) : NodeOutput(parent)
{

}

NodeDataInt* NodeOutputInt::getData()
{
    long int index{std::distance(parent->outputs.begin(), std::find(parent->outputs.begin(), parent->outputs.end(), this))};
    NodeData* rawData{parent->relations[index](&(parent->inputs))};
    NodeDataInt* data{dynamic_cast<NodeDataInt*>(rawData)};
    if(data != nullptr)
    {
        return data;
    }
    // TODO: DIE HORRIBLY IN FLAMES
    return nullptr;
}
