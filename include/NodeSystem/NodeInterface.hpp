#pragma once

#include "Global.hpp"

#include "NodeSystem/NodeInterfaceNotifier.hpp"

class Node;

class NodeInterface
{
public:
    std::string name;
	const NodeInterfaceNotifier* const notifier;
	virtual ~NodeInterface();
protected:
    const Node* parent;
    NodeInterface() = delete;
    NodeInterface(Node* parent, std::string name);
};
