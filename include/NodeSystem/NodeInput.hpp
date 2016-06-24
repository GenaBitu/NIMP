#pragma once

#include "../Global.hpp"

class Node;
class NodeData;
class NodeOutput;

class NodeInput
{
public:
    virtual NodeData* getData();
protected:
    NodeInput() = delete;
    NodeInput(Node* parent);
    virtual ~NodeInput();
private:
    friend Node;
    const Node* parent;
    NodeOutput* connection;
};
