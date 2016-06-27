#pragma once

#include "../Global.hpp"

#include "NodeData.hpp"

template<class T, class U>
class RowSelector;

#pragma pack(push)
#pragma pack(1)

typedef struct
{
    ubyte v; // value
    ubyte a; // alpha
} MonochromePixel;

#pragma pack(pop)

class NodeDataMonochrome : public NodeData
{
public:
    int width, height;
    NodeDataMonochrome() = delete;
    NodeDataMonochrome(int width, int height);
    RowSelector<NodeDataMonochrome, MonochromePixel> operator[](int index);
    const void* rawData();
    ~NodeDataMonochrome();
protected:
    friend RowSelector<NodeDataMonochrome, MonochromePixel>;
    MonochromePixel* data;
};
