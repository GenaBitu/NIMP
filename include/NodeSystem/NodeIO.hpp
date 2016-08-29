#pragma once

#include "../Global.hpp"

class Node;
class NodeData;

class NodeIO
{
public:
    std::string name;
protected:
    NodeIO() = delete;
    NodeIO(Node* parent, std::string name);
    const Node* parent;
    virtual NodeData* getData() = 0;
    ~NodeIO();
};
