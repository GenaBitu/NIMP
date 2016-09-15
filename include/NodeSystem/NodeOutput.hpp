#pragma once

#include "Global.hpp"

#include "NodeSystem/NodeIO.hpp"

class NodeInput;

class NodeOutput : public NodeIO
{
protected:
    friend NodeInput;
    NodeOutput(Node* parent, std::string name);
    virtual NodeData* getData();
    virtual ~NodeOutput();
private:
    friend Node;
    std::vector<NodeInput*> connections;
};
