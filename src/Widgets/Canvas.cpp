#include "Widgets/Canvas.hpp"

#include "Texture.hpp"
#include "Nodes/CanvasNode.hpp"
#include "Registry.hpp"

Canvas::Canvas() : width{}, height{}, IMGwidth{500}, IMGheight{500}, image{} {
}

void Canvas::initializeGL()
{
    initializeOpenGLFunctions();
    glEnable(GL_TEXTURE_2D);
    CanvasNode* canvas{dynamic_cast<CanvasNode*>(Registry::getRegistry()->intrinsic->nodes[0])};
    image = canvas->getTexture();
    //image = new Texture{};
    //image->loadBMP("tex2D.bmp");
    QColor bg{QWidget::palette().color(QPalette::Background)};
    glClearColor(bg.redF(), bg.greenF(), bg.blueF(), 1.0f);
}

void Canvas::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    renderBGCheckerboard((width - IMGwidth) / 2, (height - IMGheight) / 2, (width + IMGwidth) / 2, (height + IMGheight) / 2);
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
    renderGrid((width - IMGwidth) / 2, (height - IMGheight) / 2, (width + IMGwidth) / 2, (height + IMGheight) / 2);
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

void Canvas::renderBGCheckerboard(GLint xMin, GLint yMin, GLint xMax, GLint yMax)
{
    GLint gridSize{8};
    for(GLint i{0}; i < 1 + ((yMax - yMin - 1) / gridSize); i++)
    {
        for(GLint j{0}; j < 1 + ((xMax - xMin - 1) / gridSize); j++)
        {
            glBegin(GL_QUADS);
                if((i + j) % 2 == 0)
                {
                    glColor3ub(153, 153, 153);
                }
                else
                {
                    glColor3ub(102, 102, 102);
                }
                glVertex2i(xMin + j * gridSize, yMin + i * gridSize);
                glVertex2i(xMin + j * gridSize, glm::min(yMin + (i + 1) * gridSize, yMax));
                glVertex2i(glm::min(xMin + (j + 1) * gridSize, xMax), glm::min(yMin + (i + 1) * gridSize, yMax));
                glVertex2i(glm::min(xMin + (j + 1) * gridSize, xMax), yMin + i * gridSize);
            glEnd();
        }
    }
    /*glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2i(xMin + 1, yMin + 1);
        glVertex2i(xMin + 1, yMax - 1);
        glVertex2i(xMax - 1, yMax - 1);
        glVertex2i(xMax - 1, yMin + 1);
    glEnd();*/
}

void Canvas::renderGrid(GLint xMin, GLint yMin, GLint xMax, GLint yMax)
{
    GLint gridSize{45}, xOffset{-95}, yOffset{70};
    xOffset = xOffset % gridSize;
    yOffset = yOffset % gridSize;
    glColor3ub(0, 0, 0);
    for(GLint i{1}; i < 1 + ((xMax - xMin - xOffset - 1) / gridSize); i++)
    {
        glBegin(GL_LINES);
            glVertex2i(xMin + xOffset + i * gridSize, yMin);
            glVertex2i(xMin + xOffset + i * gridSize, yMax);
        glEnd();
    }
    for(GLint i{1}; i < 1 + ((yMax - yMin - yOffset - 1) / gridSize); i++)
    {
        glBegin(GL_LINES);
            glVertex2i(xMin, yMin + yOffset + i * gridSize);
            glVertex2i(xMax, yMin + yOffset + i * gridSize);
        glEnd();
    }
}
