#pragma once

#include "Global.hpp"

class CanvasNode;
class Texture;

class Canvas : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
    Q_DISABLE_COPY(Canvas)
public:
    Canvas();
	static void populateBar(SwitchingBar* bar, QWidget* widget);
public slots:
    void refetch();
protected:
    GLint width, height, IMGwidth, IMGheight;
	CanvasNode* node;
    Texture* image;
	QComboBox* nodeSelector;
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;
    void renderBGCheckerboard(GLint xMin, GLint yMin, GLint xMax, GLint yMax);
    void renderGrid(GLint xMin, GLint yMin, GLint xMax, GLint yMax);
private slots:
	void triggered(const QString& text);
	void canvasesChanged();
};
