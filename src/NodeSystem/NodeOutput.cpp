#include "NodeSystem/NodeOutput.hpp"

#include "NodeSystem/Node.hpp"
#include "NodeSystem/NodeIONotifier.hpp"
#include "NodeSystem/NodeInput.hpp"

const std::unordered_set<NodeInput*>& NodeOutput::getConnections()
{
    return connections;
}

void NodeOutput::setConnection(NodeInput* connection)
{
    connections.insert(connection);
    notifier->reconnected();
}

void NodeOutput::removeConnection(NodeInput* connection)
{
    connections.erase(connection);
    notifier->reconnected();
}

NodeOutput::~NodeOutput() {}

NodeOutput::NodeOutput(Node* parent, DataType type, std::string name) : NodeIO{parent, type, name}, connections{} {}

NodeData* NodeOutput::getData()
{
    long int index{std::distance(parent->outputs.begin(), std::find(parent->outputs.begin(), parent->outputs.end(), this))};
    return parent->relations[index](parent->inputs);
}

bool NodeOutput::loopCheck(NodeInput* origin)
{
	for(std::vector<NodeInput*>::const_iterator it{parent->inputs.begin()}; it != parent->inputs.end(); it++)
	{
		if((*it)->loopCheck(origin))
		{
			return true;
		}
	}
	return false;
}

void NodeOutput::invalidateCache()
{
	for(std::unordered_set<NodeInput*>::iterator it{connections.begin()}; it != connections.end(); it++)
	{
		(*it)->invalidateCache();
	}
}
