#pragma once

#include "../Global.hpp"

class Node;
class NodeData;

class NodeIO
{
protected:
    NodeIO() = delete;
    NodeIO(Node* parent, std::string name);
    const Node* parent;
    std::string name;
    virtual NodeData* getData() = 0;
    ~NodeIO();
};
