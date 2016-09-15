#pragma once

#include "Global.hpp"

#include "NodeSystem/NodeData.hpp"

template<class T, class U>
class RowSelector;

#pragma pack(push)
#pragma pack(1)

typedef struct
{
    ubyte r; // red
    ubyte g; // green
    ubyte b; // blue
    ubyte a; // alpha
} ImagePixel;

#pragma pack(pop)

class NodeDataImage : public NodeData
{
public:
    int width, height;
    NodeDataImage() = delete;
    NodeDataImage(int width, int height);
    RowSelector<NodeDataImage, ImagePixel> operator[](int index);
    const void* rawData();
    ~NodeDataImage();
protected:
    friend RowSelector<NodeDataImage, ImagePixel>;
    ImagePixel* data;
};
