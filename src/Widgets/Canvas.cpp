#include "Widgets/Canvas.hpp"

#include "NodeSystem/NodeInterfaceTypes/NodeInterfaceUniqueString.hpp"
#include "Texture.hpp"
#include "Nodes/CanvasNode.hpp"
#include "Registry.hpp"
#include "NodeSystem/NodeNotifier.hpp"

Canvas::Canvas() : width{}, height{}, IMGwidth{500}, IMGheight{500}, node{Registry::getRegistry()->intrinsic->canvases.begin()->first}, image{}, nodeSelector{new QComboBox{}}
{
	if(node != nullptr)
	{
		QObject::connect(node->notifier, &NodeNotifier::QtImageChanged, this, &Canvas::refetch);
	}
	QObject::connect(nodeSelector, static_cast<void (QComboBox::*)(const QString&)>(&QComboBox::activated), this, &Canvas::triggered);
	QObject::connect(Registry::getRegistry()->notifier, &RegistryNotifier::canvasesChanged, this, &Canvas::canvasesChanged);
}

void Canvas::populateBar(SwitchingBar* bar, QWidget* widget)
{
	Canvas* canvas{dynamic_cast<Canvas*>(widget)};
	if(canvas == nullptr)
	{
		// TODO: DIE HORRIBLY IN FLAMES
		return;
	}
	bar->addWidget(canvas->nodeSelector);
}

void Canvas::refetch()
{
    delete image;
	image = nullptr;
	if(node != nullptr)
	{
		image = node->getTexture();
	}
    update();
}

void Canvas::initializeGL()
{
    initializeOpenGLFunctions();
    glEnable(GL_TEXTURE_2D);
    //image = new Texture{};
    //image->loadBMP("tex2D.bmp");
    refetch();
    QColor bg{QWidget::palette().color(QPalette::Background)};
    glClearColor(static_cast<float>(bg.redF()), static_cast<float>(bg.greenF()), static_cast<float>(bg.blueF()), 1.0f);
	canvasesChanged();
}

void Canvas::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    GLint xMin{(width - IMGwidth) / 2};
    GLint yMin{(height - IMGheight) / 2};
    GLint xMax{(width + IMGwidth) / 2};
    GLint yMax{(height + IMGheight) / 2};
    renderBGCheckerboard(xMin, yMin, xMax, yMax);
    if(image != nullptr)
    {
        glBindTexture(GL_TEXTURE_2D, image->ID);
        glBegin(GL_QUADS);
            glColor3ub(255, 255, 255);
            glTexCoord2f(0.0f, 1.0f);
            glVertex2f(static_cast<GLfloat>(xMin), static_cast<GLfloat>(yMin));
            glTexCoord2f(1.0f, 1.0f);
            glVertex2f(static_cast<GLfloat>(xMax), static_cast<GLfloat>(yMin));
            glTexCoord2f(1.0f, 0.0f);
            glVertex2f(static_cast<GLfloat>(xMax), static_cast<GLfloat>(yMax));
            glTexCoord2f(0.0f, 0.0f);
            glVertex2f(static_cast<GLfloat>(xMin), static_cast<GLfloat>(yMax));
        glEnd();
    }
    glBindTexture(GL_TEXTURE_2D, 0);
    renderGrid(xMin, yMin, xMax, yMax);
}

void Canvas::resizeGL(int w, int h)
{
    width = w;
    height = h;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glTranslatef(-1, 1, 0);
    glScalef(2.0f / static_cast<float>(width), -2.0f / static_cast<float>(height), 1);
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

void Canvas::triggered(const QString &text)
{
	if(node != nullptr)
	{
		QObject::disconnect(node->notifier, 0, this, 0);
	}
	node = nullptr;
	std::string name = text.toStdString();
	for(std::map<CanvasNode*, std::string>::iterator it{Registry::getRegistry()->intrinsic->canvases.begin()}; it != Registry::getRegistry()->intrinsic->canvases.end(); ++it)
	{
		if(it->second == name)
		{
			node = it->first;
			break;
		}
	}
	if(node != nullptr)
	{
		QObject::connect(node->notifier, &NodeNotifier::QtImageChanged, this, &Canvas::refetch);
	}
	refetch();
}

void Canvas::canvasesChanged()
{
	nodeSelector->clear();
	if(Registry::getRegistry()->intrinsic->canvases.count(node) == 0)
	{
		node = nullptr;
	}
	for(std::map<CanvasNode*, std::string>::iterator it{Registry::getRegistry()->intrinsic->canvases.begin()}; it != Registry::getRegistry()->intrinsic->canvases.end(); ++it)
	{
		if(it->first != nullptr)
		{
			nodeSelector->insertItem(nodeSelector->count(), QString::fromStdString(it->second));
		}
	}
	nodeSelector->setCurrentIndex(nodeSelector->findText(QString::fromStdString(Registry::getRegistry()->intrinsic->canvases[node])));
	refetch();
}
