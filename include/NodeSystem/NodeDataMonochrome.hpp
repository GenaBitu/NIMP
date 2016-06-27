#pragma once

#include "../Global.hpp"

#include "NodeData.hpp"

template<class T, class U>
class RowSelector;

class NodeDataMonochrome : public NodeData
{
public:
    int width, height;
    NodeDataMonochrome() = delete;
    NodeDataMonochrome(int width, int height, ubyte* data);
    RowSelector<NodeDataMonochrome, ubyte> operator[](int index);
    ubyte* data();
    ~NodeDataMonochrome();
protected:
    friend RowSelector<NodeDataMonochrome, ubyte>;
    ubyte* rawData;
};
