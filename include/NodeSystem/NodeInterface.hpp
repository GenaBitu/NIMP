#pragma once

#include "Global.hpp"

class Node;

class NodeInterface : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(NodeInterface)
public:
    std::string name;
protected:
    const Node* parent;
    NodeInterface() = delete;
    NodeInterface(Node* parent, std::string name);
};
