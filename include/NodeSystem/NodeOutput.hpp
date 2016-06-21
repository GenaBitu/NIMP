#pragma once

#include "../Global.hpp"

class Node;
class NodeInput;

class NodeOutput
{
public:
    NodeOutput() = delete;
    NodeOutput(Node* parent);
protected:
    Node* parent;
    NodeInput* connection;
};
