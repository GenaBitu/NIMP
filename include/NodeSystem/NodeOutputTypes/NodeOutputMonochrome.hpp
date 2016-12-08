#pragma once

#include "Global.hpp"

#include "NodeSystem/NodeOutput.hpp"
#include "NodeSystem/NodeDataTypes/NodeDataMonochrome.hpp"

class NodeOutputMonochrome : public NodeOutput
{
public:
    NodeOutputMonochrome(Node* parent, DataType type, std::string name);
};
