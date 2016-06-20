#pragma once

#include "../Global.hpp"

class NodeEditor : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    NodeEditor();
protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
};
