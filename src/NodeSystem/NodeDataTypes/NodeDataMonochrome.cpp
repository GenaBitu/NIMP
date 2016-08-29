#include "NodeSystem/NodeDataTypes/NodeDataMonochrome.hpp"

#include "NodeSystem/RowSelector.hpp"

NodeDataMonochrome::NodeDataMonochrome(int width, int height) : width{width}, height{height}, data{new MonochromePixel[width * height]} {}

RowSelector<NodeDataMonochrome, MonochromePixel> NodeDataMonochrome::operator[](int index)
{
    return RowSelector<NodeDataMonochrome, MonochromePixel>{this, index, width};
}

const void* NodeDataMonochrome::rawData()
{
    return data;
}

NodeDataMonochrome::~NodeDataMonochrome()
{
    delete[] data;
}
