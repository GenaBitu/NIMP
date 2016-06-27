#include "include/NodeSystem/NodeDataMonochrome.hpp"

#include "include/NodeSystem/RowSelector.hpp"

NodeDataMonochrome::NodeDataMonochrome(int width, int height, ubyte* data) : width{width}, height{height}, rawData{new ubyte[width * height]}
{
    for(int i{0}; i < width * height; i++)
    {
        rawData[i] = data[i];
    }
}

RowSelector<NodeDataMonochrome, ubyte> NodeDataMonochrome::operator[](int index)
{
    return RowSelector<NodeDataMonochrome, ubyte>{this, index, width};
}

ubyte* NodeDataMonochrome::data()
{
    return rawData;
}

NodeDataMonochrome::~NodeDataMonochrome()
{
    delete[] rawData;
}
