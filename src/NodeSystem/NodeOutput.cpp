#include "include/NodeSystem/NodeOutput.hpp"

#include "include/NodeSystem/Node.hpp"

NodeOutput::NodeOutput(Node* parent) : parent{parent}, connections{} {}

NodeData* NodeOutput::getData()
{
    long int index{std::distance(parent->outputs.begin(), std::find(parent->outputs.begin(), parent->outputs.end(), this))};
    return parent->relations[index](&(parent->inputs));
}

NodeOutput::~NodeOutput() {}
