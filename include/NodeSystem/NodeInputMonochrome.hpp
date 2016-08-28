#pragma once

#include "../Global.hpp"

#include "NodeDataMonochrome.hpp"
#include "NodeInput.hpp"

class NodeInputMonochrome : public NodeInput
{
public:
    NodeInputMonochrome(Node* parent, std::string name);
    virtual NodeDataMonochrome* getData();
};
