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
    if(this->connection != nullptr)
    {
        this->connection->removeConnection(this);
    }
    this->connection = connection;
    emit reconnected();
}

void NodeInput::removeConnection()
{
    connection = nullptr;
    emit reconnected();
}

NodeInput::~NodeInput() {}
