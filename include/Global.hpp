#pragma once

#include <fstream> // DEBUG


#include <QApplication>
#include <QOpenGLWindow>
#include <QDebug> // DEBUG
#include <QSurface> // DEBUG
#include <QLabel>
#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_0>

#include <BlendSplitter.hpp>

class Canvas;

extern QOpenGLWindow* WINDOW;
extern BlendSplitter* SPLITTER;
extern Canvas* CANVAS;
extern QOpenGLContext* MYCONTEXT;
