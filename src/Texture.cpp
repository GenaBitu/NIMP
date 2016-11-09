#include "Texture.hpp"

#include "Widgets/Canvas.hpp"

using namespace std;

Texture::Texture() : ID{}
{
    initializeOpenGLFunctions();
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
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
    GLint* width{new GLint[maxLevel + 1]};
    GLint* height{new GLint[maxLevel + 1]};
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
