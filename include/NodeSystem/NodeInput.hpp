#pragma once

#include "Global.hpp"

#include "NodeSystem/NodeIO.hpp"

class NodeOutput;

class NodeInput : public NodeIO
{
    Q_OBJECT
    Q_DISABLE_COPY(NodeInput)
public:
    virtual NodeData* getData();
    const NodeOutput* getConnection() const;
    void setConnection(NodeOutput* connection);
    void removeConnection();
signals:
    void reconnected();
protected:
    NodeInput(Node* parent, std::string name);
    virtual ~NodeInput();
private:
    NodeOutput* connection;
};
