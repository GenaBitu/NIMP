#include "include/NodeSystem/NodeInterface.hpp"

NodeInterface::NodeInterface(Node* parent, std::string name) : name{name}, parent{parent} {}

NodeInterface::NodeInterface(const NodeInterface& other) : name{other.name}, parent{other.parent} {}

NodeInterface::NodeInterface(NodeInterface&& other) : NodeInterface{}
{
    swap(*this, other);
}

NodeInterface& NodeInterface::operator=(NodeInterface other)
{
    swap(*this, other);
    return *this;
}

void swap(NodeInterface& first, NodeInterface& second)
{
    using std::swap;
    swap(first.name, second.name);
    swap(first.parent, second.parent);
}

NodeInterface::~NodeInterface() {}

NodeInterface::NodeInterface() : name{}, parent{} {}
