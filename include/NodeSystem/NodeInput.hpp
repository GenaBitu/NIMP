#pragma once

#include "../Global.hpp"

class Node;
class NodeData;
class NodeOutput;

class NodeInput
{
protected:
    NodeInput() = delete;
    NodeInput(Node* parent);
    virtual NodeData* getData();
    virtual ~NodeInput();
private:
    Node* parent;
    NodeOutput* connection;
};
