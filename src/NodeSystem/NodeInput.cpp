#include "include/NodeSystem/NodeInput.hpp"

#include "include/NodeSystem/NodeOutput.hpp"

NodeInput::NodeInput(Node* parent) : parent{parent}, connection{} {}

NodeData* NodeInput::getData()
{
    return connection->getData();
}

NodeInput::~NodeInput() {}
