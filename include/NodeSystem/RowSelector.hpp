#pragma once

#include "../Global.hpp"

class NodeDataMonochrome;

class RowSelector
{
private:
    friend class NodeDataMonochrome;
    NodeDataMonochrome* nodeData;
    int row, width;
    RowSelector(NodeDataMonochrome* nodeData, int row, int width);
    ubyte& operator[](int index);
};
