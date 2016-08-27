#pragma once

#include "../../Global.hpp"

class Node;
class NodeOutline;

class NodeContainer : public QWidget
{
    Q_OBJECT
public:
    NodeContainer(Node* node);
    static int padding;
protected:
    Node* node;
    NodeOutline* outline;
};
