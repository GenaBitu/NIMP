#include "include/NodeSystem/NodeOutputMonochrome.hpp"

#include "include/NodeSystem/Node.hpp"

NodeOutputMonochrome::NodeOutputMonochrome(Node* parent) : NodeOutput(parent) {}

NodeDataMonochrome* NodeOutputMonochrome::getData()
{
    long int index{std::distance(parent->outputs.begin(), std::find(parent->outputs.begin(), parent->outputs.end(), this))};
    NodeData* rawData{parent->relations[index](&(parent->inputs))};
    NodeDataMonochrome* data{dynamic_cast<NodeDataMonochrome*>(rawData)};
    if(data != nullptr)
    {
        return data;
    }
    // TODO: DIE HORRIBLY IN FLAMES
    return nullptr;
}
