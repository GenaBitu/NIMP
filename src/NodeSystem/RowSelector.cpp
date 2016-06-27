#include "include/NodeSystem/RowSelector.hpp"

#include "include/NodeSystem/NodeDataMonochrome.hpp"

RowSelector::RowSelector(NodeDataMonochrome* nodeData, int row, int width) : nodeData{nodeData}, row{row}, width{width} {}

ubyte& RowSelector::operator[](int index)
{
    return nodeData->rawData[row * width + index];
}
