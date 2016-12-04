#pragma once

#include "Global.hpp"

class NodeIONotifier;
class Node;
class NodeData;
class NodeInput;

class NodeIO
{
public:
    std::string name;
	const NodeIONotifier* const notifier;
protected:
	const Node* parent;
    NodeIO() = delete;
    NodeIO(Node* parent, std::string name);
	NodeIO(const NodeIO& other) = delete;
	NodeIO& operator=(const NodeIO& other) = delete;
    virtual NodeData* getData() = 0;
	virtual bool loopCheck(NodeInput* origin) = 0;
    ~NodeIO();
};
