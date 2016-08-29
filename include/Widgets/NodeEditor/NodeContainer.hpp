#pragma once

#include "Global.hpp"

class NodeEditor;
class Node;
class NodeConnectorLeft;

class NodeContainer : public QWidget
{
    Q_OBJECT
public:
    NodeContainer(NodeEditor* parent, Node* node);
    static float padding;
    static float cornerRadius;
    static float borderWidth;
    static float headerHeight;
protected:
    Node* node;
    std::vector<NodeConnectorLeft*> inputs;
    virtual void paintEvent(QPaintEvent*);
};
