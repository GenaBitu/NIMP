#pragma once

#include "Global.hpp"

#include "NodeSystem/NodeIO.hpp"

class NodeOutput;

class NodeInput : public NodeIO
{
public:
    virtual NodeData* getData();
    NodeOutput* connection;
protected:
    NodeInput(Node* parent, std::string name);
    virtual ~NodeInput();
};
