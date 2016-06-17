#include "include/Canvas.hpp"

#include "include/Texture.hpp"

Canvas::Canvas() : image{} {}

void Canvas::initializeGL()
{
    initializeOpenGLFunctions();
    //image = new Texture{};
    glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
}

void Canvas::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(40.0f, 10.0f, 0.0f);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(100.0f, 100.0f, 0.0f);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex3f(10.0f, 70.0f, 0.0f);
    glEnd();
}

void Canvas::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glTranslatef(-1, -1, 0);
    glScalef(2.0f / w, 2.0f / h, 1);
    glMatrixMode(GL_MODELVIEW);
}
