#pragma once

#include "Global.hpp"

class NodeIONotifier;
class Node;
class NodeData;
class NodeInput;

class NodeIO
{
public:
	enum class DataType{INT, MONOCHROME, IMAGE};
	const DataType type;
    std::string name;
	const NodeIONotifier* const notifier;
protected:
	Node* const parent;
    NodeIO() = delete;
    NodeIO(Node* parent, DataType type, std::string name);
	NodeIO(const NodeIO& other) = delete;
	NodeIO& operator=(const NodeIO& other) = delete;
    virtual NodeData* getData() = 0;
	virtual bool loopCheck(NodeInput* origin) = 0;
	virtual void invalidateCache() = 0;
    ~NodeIO();
};
