#pragma once

#include "Global.hpp"

#include "NodeSystem/NodeInterface.hpp"

class NodeInterfaceString : public NodeInterface
{
    Q_OBJECT
public:
    NodeInterfaceString() = delete;
    NodeInterfaceString(Node* parent, std::string name, std::string value = "");
    const std::string& getValue();
    void setValue(std::string value);
signals:
    void valueChanged();
private:
    std::string value;
};
