#include "include/Nodes/BMPinput.hpp"

#include "include/NodeSystem/NodeOutputMonochrome.hpp"

BMPinput::BMPinput()
{
    outputs.push_back(new NodeOutputMonochrome{this});
    relations.push_back(std::bind(&BMPinput::loadBMP, this, std::placeholders::_1));
}

NodeDataMonochrome* BMPinput::loadBMP(const std::vector<NodeInput*>* const)
{
    std::string fileName{"tex2D.bmp"};
    std::ifstream file{fileName, std::ifstream::binary};
    if(!file.is_open())
    {
        qCritical() << "File " << fileName.c_str() <<" could not be opened." << endl;
        return nullptr;
    }
    BMP_HEADER header;
    file.read(reinterpret_cast<char*>(&header), sizeof(header));
    if(!file.good())
    {
        qCritical() << "File " << fileName.c_str() << " is not a correct BMP file. No BMP header found." << endl;
        return nullptr;
    }
    if((header.magic[0] != 'B') or (header.magic[1] != 'M'))
    {
        qCritical() << "File " << fileName.c_str() << " is not a correct BMP file. Wrong BMP signature." << endl;
        return nullptr;
    }
    if(header.numPlanes != 1)
    {
        qCritical() << "File " << fileName.c_str() << " is not a correct BMP file. Wrong number of planes." << endl;
        return nullptr;
    }
    if(header.BPP != 24)
    {
        qCritical() << "File " << fileName.c_str() << " is not a correct BMP file. Wrong BitCount. Use 24bpp." << endl;
        return nullptr;
    }
    if(header.compression != 0)
    {
        qCritical() << "File " << fileName.c_str() << " is not a correct BMP file. File is compressed." << endl;
        return nullptr;
    }
    if(header.imageSize == 0)
    {
        header.imageSize = 3 * header.width * header.height;
    }
    if(header.dataOffset == 0)
    {
        header.dataOffset = 54;
    }
    char* rawData{new char[header.imageSize]};
    file.seekg(header.dataOffset);
    file.read(rawData, header.imageSize);
    std::vector<std::vector<ubyte> > data;
    for(unsigned int i{0}; i < header.height; i++)
    {
        std::vector<ubyte> row;
        for(unsigned int j{0}; j < header.width; j++)
        {
            row.push_back(rawData[3 * (i * header.height + j)]);
        }
        data.push_back(row);
    }
    NodeDataMonochrome* output{new NodeDataMonochrome{header.width, header.height, data}};
    delete[] rawData;
    file.close();
    return output;
}
