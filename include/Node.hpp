#pragma once

#include "Global.hpp"

class NodeInput;
class NodeOutput;

class Node
{
public:
    Node();
protected:
    std::vector<NodeInput*> inputs;
    std::vector<NodeOutput*> outputs;
};
