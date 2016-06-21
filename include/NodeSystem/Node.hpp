#pragma once

#include "../Global.hpp"

class NodeData;
class NodeInput;
class NodeOutput;

class Node
{
public:
    Node();
protected:
    std::vector<NodeInput*> inputs;
    std::vector<NodeOutput*> outputs;
    std::vector<std::function<NodeData*(const std::vector<const NodeInput*>* const)>> relations;
};
