#pragma once

#include "Global.hpp"

class Texture;

class Canvas : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
    Q_DISABLE_COPY(Canvas)
public:
    Canvas();
public slots:
    void refetch();
protected:
    GLint width, height, IMGwidth, IMGheight;
    Texture* image;
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;
    void renderBGCheckerboard(GLint xMin, GLint yMin, GLint xMax, GLint yMax);
    void renderGrid(GLint xMin, GLint yMin, GLint xMax, GLint yMax);
};
