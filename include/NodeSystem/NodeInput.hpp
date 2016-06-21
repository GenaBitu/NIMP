#pragma once

#include "../Global.hpp"

class Node;
class NodeOutput;

class NodeInput
{
public:
    NodeInput() = delete;
    NodeInput(Node* parent);
protected:
    Node* parent;
    std::vector<NodeOutput*> connections;
};
