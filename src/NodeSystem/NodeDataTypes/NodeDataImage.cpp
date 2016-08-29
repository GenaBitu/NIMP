#include "NodeSystem/NodeDataTypes/NodeDataImage.hpp"

#include "NodeSystem/RowSelector.hpp"

NodeDataImage::NodeDataImage(int width, int height) : width{width}, height{height}, data{new ImagePixel[width * height]} {}

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
