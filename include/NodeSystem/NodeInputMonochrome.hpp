#pragma once

#include "../Global.hpp"

#include "NodeDataMonochrome.hpp"
#include "NodeInput.hpp"

class NodeInputMonochrome : public NodeInput
{
public:
    NodeInputMonochrome(Node* parent);
    virtual NodeDataMonochrome* getData();
};
