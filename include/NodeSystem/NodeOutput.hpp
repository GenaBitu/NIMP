#pragma once

#include "Global.hpp"

#include "NodeSystem/NodeIO.hpp"

class NodeOutput : public NodeIO
{
public:
	NodeOutput(Node* parent, DataType type, std::string name);
    const std::unordered_set<NodeInput*>& getConnections();
    void setConnection(NodeInput* connection);
    void removeConnection(NodeInput* connection);
    virtual ~NodeOutput();
protected:
	friend Node;
	friend NodeInput;
    virtual NodeData* getData() override;
	virtual bool loopCheck(NodeInput* origin) override;
	virtual void invalidateCache() override;
private:
    std::unordered_set<NodeInput*> connections;
};
