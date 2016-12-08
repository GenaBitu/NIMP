#pragma once

#include "Global.hpp"

#include "NodeSystem/NodeInput.hpp"
#include "NodeSystem/NodeDataTypes/NodeDataImage.hpp"

class NodeInputImage : public NodeInput
{
public:
    NodeInputImage(Node* parent, DataType type, std::string name);
};
