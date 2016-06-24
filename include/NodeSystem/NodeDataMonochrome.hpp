#pragma once

#include "../Global.hpp"

#include "NodeData.hpp"

class NodeDataMonochrome : public NodeData
{
public:
    int width, height;
    std::vector<std::vector<ubyte> > data;
    NodeDataMonochrome() = delete;
    NodeDataMonochrome(int width, int height, std::vector<std::vector<ubyte> > data);
};
