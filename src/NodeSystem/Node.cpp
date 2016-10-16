#include "NodeSystem/Node.hpp"

#include "NodeSystem/NodeInput.hpp"
#include "NodeSystem/NodeOutput.hpp"

Node::Node(int x, int y) : pos{QPoint{x, y}} {}

void Node::connect(Node* from, int numOutput, Node* to, int numInput)
{
    from->outputs[numOutput]->connections.push_back(to->inputs[numInput]);
    to->inputs[numInput]->connection = from->outputs[numOutput];
}
QPoint Node::getPos() const
{
    return pos;
}
void Node::setPos(QPoint pos)
{
    this->pos = pos;
    emit moved();
}
void Node::setPos(int x, int y)
{
    pos = QPoint{x, y};
    emit moved();
}

Node::~Node() {}
