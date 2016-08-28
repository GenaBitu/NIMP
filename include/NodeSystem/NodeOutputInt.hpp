#pragma once

#include "../Global.hpp"

#include "NodeDataInt.hpp"
#include "NodeOutput.hpp"

class NodeOutputInt : public NodeOutput
{
public:
    NodeOutputInt(Node* parent, std::string name);
    virtual NodeDataInt* getData();
};
