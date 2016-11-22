#pragma once

#include "Global.hpp"

#include "NodeSystem/NodeData.hpp"

template<class T, class U>
class RowSelector;

#pragma pack(push)
#pragma pack(1)

typedef struct
{
    float v; // value
    float a; // alpha
} MonochromePixel;

#pragma pack(pop)

class NodeDataMonochrome : public NodeData
{
public:
    int width, height;
    NodeDataMonochrome(int width, int height);
    NodeDataMonochrome(const NodeDataMonochrome& other);
    NodeDataMonochrome(NodeDataMonochrome&& other);
    NodeDataMonochrome& operator=(NodeDataMonochrome other);
    friend void swap(NodeDataMonochrome& first, NodeDataMonochrome& second);
    RowSelector<NodeDataMonochrome, MonochromePixel> operator[](int index);
    const void* rawData();
    ~NodeDataMonochrome();
protected:
    friend RowSelector<NodeDataMonochrome, MonochromePixel>;
    MonochromePixel* data;
private:
    NodeDataMonochrome();
};
