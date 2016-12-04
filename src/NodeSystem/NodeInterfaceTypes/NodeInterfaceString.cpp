#include "NodeSystem/NodeInterfaceTypes/NodeInterfaceString.hpp"

#include "NodeSystem/NodeInterfaceNotifier.hpp"

NodeInterfaceString::NodeInterfaceString(Node* parent, std::string name, std::string value) : NodeInterface{parent, name}, value{value} {}

const std::string& NodeInterfaceString::getValue()
{
    return value;
}

void NodeInterfaceString::setValue(std::string value)
{
    this->value = value;
    notifier->valueChanged();
}
