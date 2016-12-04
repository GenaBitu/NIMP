#pragma once

#include "Global.hpp"

class NodeInterfaceNotifier;

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
	NodeInterface(const NodeInterface& other) = delete;
	NodeInterface& operator=(const NodeInterface& other) = delete;
};
