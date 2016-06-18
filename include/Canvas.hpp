#pragma once

#include "Global.hpp"

class Texture;

class Canvas : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    Canvas();
protected:
    GLint width, height;
    Texture* image;
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
};
