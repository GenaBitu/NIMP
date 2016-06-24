#pragma once

#include "../Global.hpp"

#include "NodeData.hpp"

class NodeDataMonochrome : public NodeData
{
public:
    int width, height;
    std::vector<std::vector<ubyte> > data;
    NodeDataMonochrome() = delete;
    NodeDataMonochrome(std::vector<std::vector<ubyte> > data);
};
