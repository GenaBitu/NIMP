#pragma once

#include "Global.hpp"

#include "NodeSystem/NodeIO.hpp"

class NodeInput;

class NodeOutput : public NodeIO
{
public:
    std::vector<NodeInput*> connections;
protected:
    friend NodeInput;
    NodeOutput(Node* parent, std::string name);
    virtual NodeData* getData();
    virtual ~NodeOutput();
};
