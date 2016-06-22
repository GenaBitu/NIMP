#pragma once

#include "../Global.hpp"

class Node;
class NodeData;
class NodeOutput;

class NodeInput
{
public:
    NodeInput() = delete;
    NodeInput(Node* parent);
    virtual NodeData* getData() = 0;
    virtual ~NodeInput();
protected:
    Node* parent;
    NodeOutput* connection;
};
