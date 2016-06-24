#pragma once

#include "../Global.hpp"

class NodeData;
class NodeInput;
class NodeOutput;

class Node
{
public:
    std::vector<NodeInput*> inputs;
    std::vector<NodeOutput*> outputs;
    std::vector<std::function<NodeData*(const std::vector<NodeInput*>* const)> > relations;
    Node();
    static void connect(Node* from, int numOutput, Node* to, int numInput);
};
