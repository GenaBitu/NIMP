#pragma once

#include "Global.hpp"

#include "NodeSystem/NodeInterface.hpp"

class NodeInterfaceUniqueString : public NodeInterface
{
    Q_OBJECT
public:
    NodeInterfaceUniqueString() = delete;
    NodeInterfaceUniqueString(Node* parent, std::string name, std::string value = "Default", int group = 0);
    const std::string& getValue();
    void setValue(std::string value);
    ~NodeInterfaceUniqueString();
signals:
    void valueChanged();
private:
    static std::map<int, std::map<NodeInterfaceUniqueString*, std::string> > values;
    const int group;
};
