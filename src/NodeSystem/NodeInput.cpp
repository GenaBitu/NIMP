#include "NodeSystem/NodeInput.hpp"

#include "NodeSystem/NodeOutput.hpp"

NodeInput::NodeInput(Node* parent, std::string name) : NodeIO{parent, name}, connection{} {}

NodeData* NodeInput::getData()
{
    return connection->getData();
}

NodeInput::~NodeInput() {}
