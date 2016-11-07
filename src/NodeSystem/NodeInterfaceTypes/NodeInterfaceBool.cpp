#include "include/NodeSystem/NodeInterfaceTypes/NodeInterfaceBool.hpp"

NodeInterfaceBool::NodeInterfaceBool(Node* parent, std::string name, bool value) : NodeInterface(parent, name), value{value} {}

const bool& NodeInterfaceBool::getValue()
{
    return value;
}

void NodeInterfaceBool::setValue(bool value)
{
    this->value = value;
    emit valueChanged();
}
