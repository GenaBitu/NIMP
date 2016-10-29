#pragma once

#include "Global.hpp"

#include "NodeSystem/NodeIO.hpp"

class NodeOutput;

class NodeInput : public NodeIO
{
    Q_OBJECT
public:
    virtual NodeData* getData();
    const NodeOutput* getConnection() const;
    void setConnection(NodeOutput* connection);
signals:
    void reconnected();
protected:
    NodeInput(Node* parent, std::string name);
    virtual ~NodeInput();
private:
    NodeOutput* connection;
};
