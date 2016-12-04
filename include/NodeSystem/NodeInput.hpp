#pragma once

#include "Global.hpp"

#include "NodeSystem/NodeIO.hpp"

class NodeOutput;

class NodeInput : public NodeIO
{
public:
    virtual NodeData* getData() override;
    const NodeOutput* getConnection() const;
    void setConnection(NodeOutput* connection);
    void removeConnection(NodeOutput* connection);
protected:
    friend Node;
    NodeInput(Node* parent, std::string name);
	NodeInput(const NodeInput& other) = delete;
	NodeInput& operator=(const NodeInput& other) = delete;
    virtual ~NodeInput();
private:
    NodeOutput* connection;
};
