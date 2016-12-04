#include "NodeSystem/NodeOutput.hpp"

#include "NodeSystem/Node.hpp"
#include "NodeSystem/NodeIONotifier.hpp"

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

NodeOutput::NodeOutput(Node* parent, std::string name) : NodeIO{parent, name}, connections{} {}

NodeData* NodeOutput::getData()
{
    long int index{std::distance(parent->outputs.begin(), std::find(parent->outputs.begin(), parent->outputs.end(), this))};
    return parent->relations[index](parent->inputs);
}
