#pragma once

#include "Global.hpp"

#include "NodeSystem/NodeInterface.hpp"

class NodeInterfaceUniqueString : public NodeInterface
{
public:
    NodeInterfaceUniqueString() = delete;
    NodeInterfaceUniqueString(Node* parent, std::string name, std::string value = "Default", int group = 0);
    const std::string& getValue();
    void setValue(std::string value);
    ~NodeInterfaceUniqueString();
private:
    static std::map<int, std::map<NodeInterfaceUniqueString*, std::string> > values;
    const int group;
};
