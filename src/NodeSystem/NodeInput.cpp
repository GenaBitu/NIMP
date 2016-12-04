#include "NodeSystem/NodeInput.hpp"

#include "NodeSystem/NodeOutput.hpp"
#include "NodeSystem/NodeIONotifier.hpp"

NodeInput::NodeInput(Node* parent, std::string name) : NodeIO{parent, name}, connection{} {}

NodeData* NodeInput::getData()
{
    return connection != nullptr ? connection->getData() : nullptr;
}

bool NodeInput::loopCheck(NodeInput* origin)
{
	if(origin == this)
	{
		return true;
	}
	return connection != nullptr ? connection->loopCheck(origin) : false;
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
    notifier->reconnected();
}

void NodeInput::removeConnection(NodeOutput* connection)
{
    if(this->connection == connection)
    {
        this->connection = nullptr;
        notifier->reconnected();
    }
}

NodeInput::~NodeInput() {}
