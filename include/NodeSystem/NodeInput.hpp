#pragma once

#include "../Global.hpp"

#include "NodeIO.hpp"

class NodeOutput;

class NodeInput : public NodeIO
{
public:
    virtual NodeData* getData();
protected:
    NodeInput(Node* parent, std::string name);
    virtual ~NodeInput();
private:
    friend Node;
    NodeOutput* connection;
};
