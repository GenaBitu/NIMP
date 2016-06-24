#include "include/NodeSystem/Node.hpp"

#include "include/NodeSystem/NodeInput.hpp"
#include "include/NodeSystem/NodeOutput.hpp"

Node::Node() {}

void Node::connect(Node* from, int numOutput, Node* to, int numInput)
{
    from->outputs[numOutput]->connections.push_back(to->inputs[numInput]);
    to->inputs[numInput]->connection = from->outputs[numOutput];
}
