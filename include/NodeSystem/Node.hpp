#pragma once

#include "Global.hpp"

class NodeData;
class NodeInput;
class NodeOutput;

class Node : public QObject
{
    Q_OBJECT
public:
    int x, y;
    std::vector<NodeInput*> inputs;
    std::vector<NodeOutput*> outputs;
    std::vector<std::function<NodeData*(const std::vector<NodeInput*>* const)> > relations;
    Node(int x = 0, int y = 0);
    static void connect(Node* from, int numOutput, Node* to, int numInput);
    virtual std::string nodeName() = 0;
    virtual ~Node();
signals:
    void moved();
};
