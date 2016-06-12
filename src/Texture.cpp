#include "include/Texture.hpp"

#include "include/Canvas.hpp"

using namespace std;

Texture::Texture() : ID{}
{
    initializeOpenGLFunctions();
    glGenTextures(1, &ID);
}

Texture::Texture(const Texture &other) : Texture{}
{
    *this = other;
}

Texture& Texture::operator=(const Texture& other)
{
    GLint maxLevel{}, wrapS{}, wrapT{}, magFilter{}, minFilter{};
    glBindTexture(GL_TEXTURE_2D, other.ID);
    glGetTexParameteriv(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, &maxLevel);
    GLint width[maxLevel + 1], height[maxLevel + 1];
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &width[0]);
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &height[0]);
    glGetTexParameteriv(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, &wrapS);
    glGetTexParameteriv(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, &wrapT);
    glGetTexParameteriv(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, &magFilter);
    glGetTexParameteriv(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, &minFilter);
    GLubyte* data{new GLubyte[(maxLevel > 0 ? 2 : 1) * 4 * width[0] * height[0]]};
    int dataPos{0};
    for(GLint level{0}; level <= maxLevel; level++)
    {
        glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &width[level]);
        glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &height[level]);
        glGetTexImage(GL_TEXTURE_2D, level, GL_RGBA, GL_UNSIGNED_BYTE, &data[dataPos]);
        dataPos += 4 * width[level] * height[level];
    }
    glBindTexture(GL_TEXTURE_2D, ID);
    dataPos = 0;
    for(GLint level{0}; level <= maxLevel; level++)
    {
        glTexImage2D(GL_TEXTURE_2D, level, GL_RGBA, width[level], height[level], 0, GL_RGB, GL_UNSIGNED_BYTE, &data[dataPos]);
        dataPos += 4 * width[level] * height[level];
    }
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapS);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
    delete[] data;
    return *this;
}

void Texture::loadBMP(std::string fileName)
{
    glBindTexture(GL_TEXTURE_2D, ID);
    ifstream file{fileName, ifstream::binary};
    if(!file.is_open())
    {
        qCritical() << "File " << fileName.c_str() <<" could not be opened." << endl;
        return;
    }
    BMP_HEADER header;
    file.read(reinterpret_cast<char*>(&header), sizeof(header));
    if(!file.good())
    {
        qCritical() << "File " << fileName.c_str() << " is not a correct BMP file. No BMP header found." << endl;
        return;
    }
    if((header.magic[0] != 'B') or (header.magic[1] != 'M'))
    {
        qCritical() << "File " << fileName.c_str() << " is not a correct BMP file. Wrong BMP signature." << endl;
        return;
    }
    if(header.numPlanes != 1)
    {
        qCritical() << "File " << fileName.c_str() << " is not a correct BMP file. Wrong number of planes." << endl;
        return;
    }
    if(header.BPP != 24)
    {
        qCritical() << "File " << fileName.c_str() << " is not a correct BMP file. Wrong BitCount. Use 24bpp." << endl;
        return;
    }
    if(header.compression != 0)
    {
        qCritical() << "File " << fileName.c_str() << " is not a correct BMP file. File is compressed." << endl;
        return;
    }
    if(header.imageSize == 0)
    {
        header.imageSize = 3 * header.width * header.height;
    }
    if(header.dataOffset == 0)
    {
        header.dataOffset = 54;
    }
    char* data{new char[header.imageSize]};
    file.seekg(header.dataOffset);
    file.read(data, header.imageSize);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, header.width, header.height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    delete[] data;
    file.close();
}
