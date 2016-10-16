#include "Widgets/NodeEditor/NodePath.hpp"

#include "Registry.hpp"
#include "WidgetActions/States/ActionState.hpp"
#include "Widgets/NodeEditor.hpp"

NodePath::NodePath(NodeEditor* parent, NodeOutputGraphics* left, NodeInputGraphics* right) : Selectable(parent), left{left}, right{right}
{
    (*state->palette)["path"] = std::make_tuple("NodePath", "NodePathActive");
    left->connections.push_back(this);
    right->connection = this;
    lower();
}

void NodePath::reposition()
{
    resize(10000, 10000);
    double yOffset{0.5 * Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"]};
    double lX{static_cast<double>(left->parentWidget()->x() + left->x() + left->width())};
    double lY{left->parentWidget()->y() + left->y() + yOffset};
    double rX{static_cast<double>(right->parentWidget()->x() + right->x())};
    double rY{right->parentWidget()->y() + right->y() + yOffset};
    path = new QPainterPath{};
    path->moveTo(lX, lY);
    path->cubicTo(lX + Registry::getRegistry()->extrinsic->GUI->dimensions["NodePathSharpness"], lY, rX - Registry::getRegistry()->extrinsic->GUI->dimensions["NodePathSharpness"], rY, rX, rY);
    QPainterPathStroker stroker;
    stroker.setWidth(Registry::getRegistry()->extrinsic->GUI->dimensions["NodePathClickableWidth"]);
    QPainterPath thick{stroker.createStroke(*path)};
    setMask(thick.toFillPolygon().toPolygon());
    state->changeMask(&thick);
    update();
}

void NodePath::paintEvent(QPaintEvent*)
{
    QPainter painter{this};
    painter.setRenderHint(QPainter::Antialiasing);
    QPen pen{state->getColour("path"), Registry::getRegistry()->extrinsic->GUI->dimensions["NodePathWidth"]};
    painter.setPen(pen);
    painter.drawPath(*path);
}
