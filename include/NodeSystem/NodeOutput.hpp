#pragma once

#include "Global.hpp"

#include "NodeSystem/NodeIO.hpp"

class NodeInput;

class NodeOutput : public NodeIO
{
Q_OBJECT
public:
    const std::unordered_set<NodeInput*>& getConnections();
    void setConnection(NodeInput* connection);
    void removeConnection(NodeInput* connection);
    virtual ~NodeOutput();
signals:
    void reconnected();
protected:
    friend Node;
    friend NodeInput;
    NodeOutput(Node* parent, std::string name);
    virtual NodeData* getData();
private:
    std::unordered_set<NodeInput*> connections;
};
