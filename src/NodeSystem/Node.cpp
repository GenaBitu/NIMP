#include "NodeSystem/Node.hpp"

#include "NodeSystem/NodeInput.hpp"
#include "NodeSystem/NodeOutput.hpp"

Node::Node(int x, int y) : x{x}, y{y} {}

void Node::connect(Node* from, int numOutput, Node* to, int numInput)
{
    from->outputs[numOutput]->connections.push_back(to->inputs[numInput]);
    to->inputs[numInput]->connection = from->outputs[numOutput];
}

Node::~Node() {}
