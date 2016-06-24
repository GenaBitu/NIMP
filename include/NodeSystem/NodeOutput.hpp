#pragma once

#include "../Global.hpp"

class Node;
class NodeData;
class NodeInput;

class NodeOutput
{
protected:
    friend NodeInput;
    NodeOutput() = delete;
    NodeOutput(Node* parent);
    virtual NodeData* getData();
    virtual ~NodeOutput();
private:
    friend Node;
    const Node* parent;
    std::vector<NodeInput*> connections;
};
