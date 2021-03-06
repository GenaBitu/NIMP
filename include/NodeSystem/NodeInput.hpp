#pragma once

#include "Global.hpp"

#include "NodeSystem/NodeIO.hpp"

class NodeOutput;

class NodeInput : public NodeIO
{
public:
	NodeInput(Node* parent, DataType type, std::string name);
    virtual NodeData* getData() override;
    const NodeOutput* getConnection() const;
    void setConnection(NodeOutput* connection);
    void removeConnection(NodeOutput* connection);
protected:
	friend Node;
	friend NodeOutput;
	NodeInput(const NodeInput& other) = delete;
	NodeInput& operator=(const NodeInput& other) = delete;
	virtual bool loopCheck(NodeInput* origin) override;
	virtual void invalidateCache() override;
    virtual ~NodeInput();
private:
    NodeOutput* connection;
};
