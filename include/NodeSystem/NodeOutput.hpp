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
signals:
    void reconnected();
protected:
    friend NodeInput;
    NodeOutput(Node* parent, std::string name);
    virtual NodeData* getData();
    virtual ~NodeOutput();
private:
    std::unordered_set<NodeInput*> connections;
};
