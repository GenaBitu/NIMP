#include "NodeSystem/Node.hpp"

#include "NodeSystem/NodeInput.hpp"
#include "NodeSystem/NodeOutput.hpp"

Node::Node(int x, int y) : inputs{}, outputs{}, relations{}, pos{QPoint{x, y}} {}

void Node::connect(Node* from, int numOutput, Node* to, int numInput)
{
    connect(from->outputs[numOutput], to->inputs[numInput]);
}

void Node::connect(NodeOutput* from, NodeInput* to)
{
    from->setConnection(to);
    to->setConnection(from);
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
