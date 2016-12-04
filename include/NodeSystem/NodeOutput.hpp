#pragma once

#include "Global.hpp"

#include "NodeSystem/NodeIO.hpp"

class NodeInput;

class NodeOutput : public NodeIO
{
public:
    const std::unordered_set<NodeInput*>& getConnections();
    void setConnection(NodeInput* connection);
    void removeConnection(NodeInput* connection);
    virtual ~NodeOutput();
protected:
    friend Node;
    friend NodeInput;
    NodeOutput(Node* parent, std::string name);
    virtual NodeData* getData() override;
	virtual bool loopCheck(NodeInput* origin) override;
	virtual void invalidateCache() override;
private:
    std::unordered_set<NodeInput*> connections;
};
