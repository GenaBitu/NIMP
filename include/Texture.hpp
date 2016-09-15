#pragma once

#include "Global.hpp"

class Texture : public QOpenGLFunctions
{
public:
    GLuint ID;
    Texture();
    Texture(const Texture& other);
    Texture& operator=(const Texture& other);
};
