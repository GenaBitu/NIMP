#include "include/Canvas.hpp"

#include "include/Texture.hpp"

Canvas::Canvas() : image{} {}

void Canvas::initializeGL()
{
    initializeOpenGLFunctions();
    image = new Texture{};
}
