#pragma once

#include "Global.hpp"

class NodeData;
class NodeInput;
class NodeOutput;
class NodeInterface;

class Node : public QObject
{
    Q_OBJECT
public:
    std::vector<NodeInput*> inputs;
    std::vector<NodeOutput*> outputs;
    std::vector<NodeInterface*> interfaces;
    std::vector<std::function<NodeData*(const std::vector<NodeInput*>)> > relations;
    Node(int x = 10, int y = 10);
    static void connect(Node* from, int numOutput, Node* to, int numInput);
    static void connect(NodeOutput* from, NodeInput* to);
    static void disconnect(Node* from, int numOutput, Node* to, int numInput);
    static void disconnect(NodeOutput* from, NodeInput* to);
    virtual std::string nodeName() = 0;
    QPoint getPos() const;
    void setPos(QPoint pos);
    void setPos(int x, int y);
    virtual ~Node();
signals:
    void moved();
    void deleted();
private:
    QPoint pos;
};
