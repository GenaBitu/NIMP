#include "include/Widgets/NodeEditor/NodeContainer.hpp"

#include "include/Widgets/NodeEditor/NodeOutline.hpp"

int NodeContainer::padding{10};

NodeContainer::NodeContainer(Node* node) : node{node}, outline{new NodeOutline{}}
{

}
