#include "Widgets/NodeEditor/TempPath.hpp"

#include "Registry.hpp"
#include "Widgets/NodeEditor.hpp"

TempPath::TempPath(NodeEditor* parent, NodeInputGraphics* right) : QWidget{parent}, left{nullptr}, right{right}, path{}
{
    grabMouse();
    parent->select(nullptr);
    raise();
    //lower();
}

TempPath::TempPath(NodeEditor* parent, NodeOutputGraphics* left) : QWidget{parent}, left{left}, right{nullptr}, path{}
{
    grabMouse();
    parent->select(nullptr);
    raise();
    //lower();
}

void TempPath::mouseMoveEvent(QMouseEvent* event)
{
    qDebug() << "MOVE" << endl;
    resize(10000, 10000);
    double yOffset{0.5 * Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"]};
    double lX, lY, rX, rY;
    if(left != nullptr)
    {
        lX = static_cast<double>(left->parentWidget()->x() + left->x() + left->width());
        lY = left->parentWidget()->y() + left->y() + yOffset;
    }
    else
    {
        //lX = event->x();
        //lY = event->y();
        lX = 10;
        lY = 10;
    }
    if(right != nullptr)
    {
        rX = static_cast<double>(right->parentWidget()->x() + right->x());
        rY = right->parentWidget()->y() + right->y() + yOffset;
    }
    else
    {
        rX = event->x();
        rY = event->y();
    }
    path = new QPainterPath{};
    path->moveTo(lX, lY);
    path->cubicTo(lX + Registry::getRegistry()->extrinsic->GUI->dimensions["NodePathSharpness"], lY, rX - Registry::getRegistry()->extrinsic->GUI->dimensions["NodePathSharpness"], rY, rX, rY);
    repaint();
}

void TempPath::mouseReleaseEvent(QMouseEvent*)
{
    qDebug() << "RELEASE" << endl;
    releaseMouse();
    //delete this;
}

void TempPath::paintEvent(QPaintEvent*)
{
    qDebug() << "PAINT" << endl;
    QPainter painter{this};
    painter.setRenderHint(QPainter::Antialiasing);
    QPen pen{Registry::getRegistry()->extrinsic->GUI->palette["NodePathActive"], Registry::getRegistry()->extrinsic->GUI->dimensions["NodePathWidth"]};
    painter.setPen(pen);
    painter.drawPath(*path);
}
