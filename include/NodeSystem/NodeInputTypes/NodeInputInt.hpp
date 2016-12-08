#pragma once

#include "Global.hpp"

#include "NodeSystem/NodeInput.hpp"
#include "NodeSystem/NodeDataTypes/NodeDataInt.hpp"

class NodeInputInt : public NodeInput
{
public:
    NodeInputInt(Node* parent, std::string name);
};
