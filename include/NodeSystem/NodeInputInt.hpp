#pragma once

#include "../Global.hpp"

#include "NodeDataInt.hpp"
#include "NodeInput.hpp"

class NodeInputInt : public NodeInput
{
public:
    NodeInputInt(Node* parent, std::string name);
    virtual NodeDataInt* getData();
};
