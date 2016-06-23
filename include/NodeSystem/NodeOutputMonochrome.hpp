#pragma once

#include "../Global.hpp"

#include "NodeDataMonochrome.hpp"
#include "NodeOutput.hpp"

class NodeOutputMonochrome : public NodeOutput
{
public:
    NodeOutputMonochrome(Node* parent);
    virtual NodeDataMonochrome* getData();
};
