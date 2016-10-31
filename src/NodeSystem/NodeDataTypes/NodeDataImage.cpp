#include "NodeSystem/NodeDataTypes/NodeDataImage.hpp"

#include "NodeSystem/RowSelector.hpp"

NodeDataImage::NodeDataImage(int width, int height) : width{width}, height{height}, data{new ImagePixel[width * height]} {}

NodeDataImage::NodeDataImage(const NodeDataImage& other) : width{other.width}, height{other.height}, data{width * height ? new ImagePixel[width * height] : nullptr}
{
    std::copy(other.data, other.data + (width * height), data);
}

NodeDataImage::NodeDataImage(NodeDataImage&& other) : NodeDataImage{}
{
    swap(*this, other);
}

NodeDataImage& NodeDataImage::operator=(NodeDataImage other)
{
    swap(*this, other);
    return *this;
}

void swap(NodeDataImage& first, NodeDataImage& second)
{
    using std::swap;
    swap(first.width, second.width);
    swap(first.height, second.height);
    swap(first.data, second.data);
}

RowSelector<NodeDataImage, ImagePixel> NodeDataImage::operator[](int index)
{
    return RowSelector<NodeDataImage, ImagePixel>{this, index, width};
}

const void* NodeDataImage::rawData()
{
    return data;
}

NodeDataImage::~NodeDataImage()
{
    delete[] data;
}

NodeDataImage::NodeDataImage() : width{}, height{}, data{} {}
