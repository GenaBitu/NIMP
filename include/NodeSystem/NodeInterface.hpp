#pragma once

#include "Global.hpp"

class Node;

class NodeInterface
{
public:
    std::string name;
protected:
    const Node* parent;
    NodeInterface(Node* parent, std::string name);
    NodeInterface(const NodeInterface& other);
    NodeInterface(NodeInterface&& other);
    NodeInterface& operator=(NodeInterface other);
    friend void swap(NodeInterface& first, NodeInterface& second);
    virtual ~NodeInterface();
private:
    NodeInterface();
};
