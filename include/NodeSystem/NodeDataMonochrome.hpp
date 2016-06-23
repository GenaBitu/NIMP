#pragma once

#include "../Global.hpp"

#include "NodeData.hpp"

typedef unsigned char ubyte;

class NodeDataMonochrome : public NodeData
{
public:
    std::vector<std::vector<ubyte> > data;
    NodeDataMonochrome() = delete;
    NodeDataMonochrome(std::vector<std::vector<ubyte> > data);
};
