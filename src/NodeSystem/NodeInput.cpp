#include "NodeSystem/NodeInput.hpp"

#include "NodeSystem/Node.hpp"
#include "NodeSystem/NodeOutput.hpp"
#include "NodeSystem/NodeIONotifier.hpp"

NodeData* NodeInput::getData()
{
    return connection != nullptr ? connection->getData() : nullptr;
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

NodeInput::NodeInput(Node* parent, DataType type, std::string name) : NodeIO{parent, type, name}, connection{} {}

bool NodeInput::loopCheck(NodeInput* origin)
{
	if(origin == this)
	{
		return true;
	}
	return connection != nullptr ? connection->loopCheck(origin) : false;
}

void NodeInput::invalidateCache()
{
	parent->invalidateCache();
}

NodeInput::~NodeInput() {}
