#include "include/NodeEditor.hpp"

NodeEditor::NodeEditor() {}

void NodeEditor::initializeGL()
{
    initializeOpenGLFunctions();
    QColor bg{QWidget::palette().color(QPalette::Background)};
    glClearColor(bg.redF(), bg.greenF(), bg.blueF(), 1.0f);
}

void NodeEditor::paintGL()
{

}

void NodeEditor::resizeGL(int w, int h)
{

}
