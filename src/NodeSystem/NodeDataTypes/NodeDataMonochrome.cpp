#include "NodeSystem/NodeDataTypes/NodeDataMonochrome.hpp"

#include "RowSelector.hpp"

NodeDataMonochrome::NodeDataMonochrome(int width, int height) : width{width}, height{height}, data{new MonochromePixel[width * height]} {}

NodeDataMonochrome::NodeDataMonochrome(const NodeDataMonochrome& other) : width{other.width}, height{other.height}, data{width * height ? new MonochromePixel[width * height] : nullptr}
{
    std::copy(other.data, other.data + (width * height), data);
}

NodeDataMonochrome::NodeDataMonochrome(NodeDataMonochrome&& other) : NodeDataMonochrome{}
{
    swap(*this, other);
}

NodeDataMonochrome& NodeDataMonochrome::operator=(NodeDataMonochrome other)
{
    swap(*this, other);
    return *this;
}

void swap(NodeDataMonochrome& first, NodeDataMonochrome& second)
{
    using std::swap;
    swap(first.width, second.width);
    swap(first.height, second.height);
    swap(first.data, second.data);
}

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

NodeDataMonochrome::NodeDataMonochrome() : width{}, height{}, data{} {}
