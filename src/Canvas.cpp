#include "include/Canvas.hpp"

#include "include/Texture.hpp"

Canvas::Canvas() : width{}, height{}, image{} {
}

void Canvas::initializeGL()
{
    initializeOpenGLFunctions();
    glEnable(GL_TEXTURE_2D);
    image = new Texture{};
    image->loadBMP("tex2D.bmp");
    QColor bg{QWidget::palette().color(QPalette::Background)};
    glClearColor(bg.redF(), bg.greenF(), bg.blueF(), 1.0f);
}

void Canvas::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glBindTexture(GL_TEXTURE_2D, image->ID);
    glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glTexCoord2f(0.0f, 1.0f);
        glVertex2f(50.0f, 50.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex2f(width - 50.0f, 50.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex2f(width - 50.0f, height - 50.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex2f(50.0f, height - 50.0f);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glBegin(GL_QUADS);
        glColor3ub(255, 0, 0);
        glVertex2f(0.0f, 0.0f);
        glColor3ub(0, 255, 0);
        glVertex2f(40.0f, 10.0f);
        glColor3ub(0, 0, 255);
        glVertex2f(100.0f, 100.0f);
        glColor3ub(255, 255, 0);
        glVertex2f(10.0f, 70.0f);
    glEnd();
}

void Canvas::resizeGL(int w, int h)
{
    width = w;
    height = h;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glTranslatef(-1, 1, 0);
    glScalef(2.0f / width, -2.0f / height, 1);
    glMatrixMode(GL_MODELVIEW);
}
