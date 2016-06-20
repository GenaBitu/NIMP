#pragma once

#include "../Global.hpp"

class NodeOutput;

class NodeInput
{
public:
    NodeInput();
protected:
    std::vector<NodeOutput*> connections;
};
