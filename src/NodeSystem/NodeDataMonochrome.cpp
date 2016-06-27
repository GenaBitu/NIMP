#include "include/NodeSystem/NodeDataMonochrome.hpp"

#include "include/NodeSystem/RowSelector.hpp"

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
