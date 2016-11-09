#pragma once

#include "Global.hpp"

#include "NodeSystem/Node.hpp"

#pragma pack(push)
#pragma pack(1)

typedef struct {
    char magic[2];
    uint32_t fileSize;
    uint32_t reserved0;
    uint32_t dataOffset;
    uint32_t headerSize;    // 40
    uint32_t width;
    uint32_t height;
    uint16_t numPlanes;     // 1
    uint16_t BPP;           // Bits per pixel
    uint32_t compression;   // 0
    uint32_t imageSize;
    uint32_t hRes;          // In pixels per meter
    uint32_t vRes;
    uint32_t colorsUsed;
    uint32_t colorsImportant;
} BMP_HEADER;

#pragma pack(pop)

class NodeDataImage;

class BMPinput : public Node
{
    Q_OBJECT
public:
    BMPinput(std::string filename, int x = 10, int y = 10);
    virtual std::string nodeName() override;
private:
    std::string filename;
    NodeDataImage* loadBMP(const std::vector<NodeInput*>* const);
};
