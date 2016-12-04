#pragma once

#include "Global.hpp"

class NodeIONotifier;
class Node;
class NodeData;

class NodeIO
{
public:
    std::string name;
	const NodeIONotifier* const notifier;
protected:
	const Node* parent;
    NodeIO() = delete;
    NodeIO(Node* parent, std::string name);
    virtual NodeData* getData() = 0;
    ~NodeIO();
};
