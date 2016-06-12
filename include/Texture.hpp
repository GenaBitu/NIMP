#pragma once

#include "Global.hpp"

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

class Texture : public QOpenGLFunctions
{
public:
    GLuint ID;
    Texture();
    Texture(const Texture& other);
    Texture& operator=(const Texture& other);
    void loadBMP(std::string fileName);
};
