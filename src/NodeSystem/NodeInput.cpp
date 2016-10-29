#include "NodeSystem/NodeInput.hpp"

#include "NodeSystem/NodeOutput.hpp"

NodeInput::NodeInput(Node* parent, std::string name) : NodeIO{parent, name}, connection{} {}

NodeData* NodeInput::getData()
{
    return connection->getData();
}

const NodeOutput* NodeInput::getConnection() const
{
    return connection;
}

void NodeInput::setConnection(NodeOutput* connection)
{
    this->connection = connection;
    emit reconnected();
}

NodeInput::~NodeInput() {}
