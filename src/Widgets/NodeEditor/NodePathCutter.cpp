#include "Widgets/NodeEditor/NodePathCutter.hpp"

#include "Widgets/NodeEditor.hpp"

NodePathCutter::NodePathCutter(NodeEditor* parent, QPoint origin) : Selectable{parent}, origin{origin}
{
    grabMouse();
    changeState(States::SELECTED);
}

void NodePathCutter::mouseReleaseEvent(QMouseEvent*)
{
    releaseMouse();
    //delete this;
}

void NodePathCutter::paintEvent(QPaintEvent*)
{

}
