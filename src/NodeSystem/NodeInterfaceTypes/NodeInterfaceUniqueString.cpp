#include "NodeSystem/NodeInterfaceTypes/NodeInterfaceUniqueString.hpp"

std::map<int, std::map<NodeInterfaceUniqueString*, std::string> > NodeInterfaceUniqueString::values{};

NodeInterfaceUniqueString::NodeInterfaceUniqueString(Node* parent, std::string name, std::string value, int group) : NodeInterface{parent, name}, group{group}
{
    setValue(value);
}

const std::string& NodeInterfaceUniqueString::getValue()
{
    return values[group][this];
}

void NodeInterfaceUniqueString::setValue(std::string value)
{
    values[group].erase(this);
    bool rewritten{true};
    while(rewritten)
    {
        rewritten = false;
        for(std::map<NodeInterfaceUniqueString*, std::string>::iterator it{values[group].begin()}; it != values[group].end(); it++)
        {
            if(it->second == value)
            {
                value = value + ".copy";
                rewritten = true;
                break;
            }
        }
    }
    values[group][this] = value;
    notifier->valueChanged();
}

NodeInterfaceUniqueString::~NodeInterfaceUniqueString()
{
    values[group].erase(this);
}
