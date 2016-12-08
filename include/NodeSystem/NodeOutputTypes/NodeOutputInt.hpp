#pragma once

#include "Global.hpp"

#include "NodeSystem/NodeOutput.hpp"
#include "NodeSystem/NodeDataTypes/NodeDataInt.hpp"

class NodeOutputInt : public NodeOutput
{
public:
    NodeOutputInt(Node* parent, std::string name);
};
