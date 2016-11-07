#pragma once

#include "Global.hpp"

#include "NodeSystem/NodeInterface.hpp"

class NodeInterfaceBool : public NodeInterface
{
    Q_OBJECT
public:
    NodeInterfaceBool() = delete;
    NodeInterfaceBool(Node* parent, std::string name, bool value = false);
    const bool& getValue();
    void setValue(bool value);
signals:
    void valueChanged();
private:
    bool value;
};
