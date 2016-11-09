#pragma once

#include "Global.hpp"

#include "NodeSystem/NodeInput.hpp"
#include "NodeSystem/NodeDataTypes/NodeDataMonochrome.hpp"

class NodeInputMonochrome : public NodeInput
{
public:
    NodeInputMonochrome(Node* parent, std::string name);
    virtual NodeDataMonochrome* getData() override;
};
