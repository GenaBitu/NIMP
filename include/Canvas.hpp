#pragma once

#include "Global.hpp"

class Texture;

class Canvas : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    Canvas();
protected:
    Texture* image;
    void initializeGL();
};
