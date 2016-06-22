#pragma once

#include "../Global.hpp"

class Node;
class NodeData;
class NodeInput;

class NodeOutput
{
public:
    NodeOutput() = delete;
    NodeOutput(Node* parent);
    virtual NodeData* getData() = 0;
    virtual ~NodeOutput();
protected:
    Node* parent;
    std::vector<NodeInput*> connections;
};
