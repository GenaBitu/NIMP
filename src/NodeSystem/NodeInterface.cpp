#include "NodeSystem/NodeInterface.hpp"

NodeInterface::~NodeInterface()
{
	delete notifier;
}

NodeInterface::NodeInterface(Node* parent, std::string name) : name{name}, notifier{new NodeInterfaceNotifier{}}, parent{parent} {}
