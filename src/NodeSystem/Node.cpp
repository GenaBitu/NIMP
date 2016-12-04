#include "NodeSystem/Node.hpp"

#include "NodeSystem/NodeInput.hpp"
#include "NodeSystem/NodeOutput.hpp"
#include "Registry.hpp"
#include "NodeSystem/NodeInterface.hpp"
#include "NodeSystem/NodeNotifier.hpp"

Node::Node(int x, int y) : inputs{}, outputs{}, interfaces{}, relations{}, notifier{new NodeNotifier{}}, pos{QPoint{x, y}}
{
    Registry::getRegistry()->intrinsic->nodes.push_back(this);
    emit Registry::getRegistry()->notifier->nodeAdded(this);
}

void swap(Node& first, Node& second)
{
	using std::swap;
	swap(first.inputs, second.inputs);
	swap(first.outputs, second.outputs);
	swap(first.interfaces, second.interfaces);
	swap(first.relations, second.relations);
	swap(first.notifier, second.notifier);
	swap(first.pos, second.pos);
}

void Node::connect(Node* from, int numOutput, Node* to, int numInput)
{
    connect(from->outputs[numOutput], to->inputs[numInput]);
}

void Node::connect(NodeOutput* from, NodeInput* to)
{
    from->setConnection(to);
    to->setConnection(from);
}

void Node::disconnect(Node* from, int numOutput, Node* to, int numInput)
{
    disconnect(from->outputs[numOutput], to->inputs[numInput]);
}

void Node::disconnect(NodeOutput* from, NodeInput* to)
{
    from->removeConnection(to);
    to->removeConnection(from);
}

QPoint Node::getPos() const
{
    return pos;
}

void Node::setPos(QPoint pos)
{
    this->pos = pos;
    notifier->moved();
}

void Node::setPos(int x, int y)
{
    pos = QPoint{x, y};
    notifier->moved();
}

Node::~Node()
{
    for(std::vector<NodeInterface*>::iterator it{interfaces.begin()}; it != interfaces.end();)
    {
        delete (*it);
        it = interfaces.erase(it);
    }
    for(std::vector<NodeInput*>::iterator it{inputs.begin()}; it != inputs.end();)
    {
        if((*it)->connection != nullptr)
        {
            (*it)->connection->connections.erase(*it);
            emit (*it)->connection->reconnected();
        }
        delete (*it);
        it = inputs.erase(it);
    }
    for(std::vector<NodeOutput*>::iterator it{outputs.begin()}; it != outputs.end();)
    {
        for(std::unordered_set<NodeInput*>::iterator jt{(*it)->connections.begin()}; jt != (*it)->connections.end(); jt++)
        {
            if((*jt)->connection == (*it))
            {
                (*jt)->connection = nullptr;
                emit (*jt)->reconnected();
            }
        }
        delete (*it);
        it = outputs.erase(it);
    }
    std::vector<Node*>& vec{Registry::getRegistry()->intrinsic->nodes};
    vec.erase(std::remove(vec.begin(), vec.end(), this), vec.end());
    notifier->deleted();
    delete notifier;
}
