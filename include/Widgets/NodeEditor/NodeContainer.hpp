#pragma once

#include "../../Global.hpp"

class Node;

class NodeContainer : public QWidget
{
    Q_OBJECT
public:
    NodeContainer(Node* node);
protected:
    Node* node;
};
