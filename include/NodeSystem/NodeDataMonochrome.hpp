#pragma once

#include "../Global.hpp"

#include "NodeData.hpp"

class RowSelector;

class NodeDataMonochrome : public NodeData
{
public:
    int width, height;
    NodeDataMonochrome() = delete;
    NodeDataMonochrome(int width, int height, ubyte* data);
    RowSelector operator[](int index);
    ubyte* data();
    ~NodeDataMonochrome();
protected:
    friend RowSelector;
    ubyte* rawData;
};
