#pragma once

#include <fstream> // DEBUG
#include <functional>

#include <glm/common.hpp>

#include <QApplication>
#include <QMainWindow>
#include <QDebug> // DEBUG
#include <QLabel>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QPainter>

#include <BlendSplitter.hpp>

typedef unsigned char ubyte;

class CanvasNode;

extern CanvasNode* CNVS;
