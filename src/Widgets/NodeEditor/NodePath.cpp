#include "Widgets/NodeEditor.hpp"

#include "Registry.hpp"

NodeEditor::NodePath::NodePath(NodeEditor* parent, NodeConnectorRight* left, NodeConnectorLeft* right) : QWidget(parent), left{left}, right{right}
{
    resize(parent->width(), parent->height());
}

void NodeEditor::NodePath::paintEvent(QPaintEvent*)
{
    QPainter painter{this};
    painter.setRenderHint(QPainter::Antialiasing);
    QPainterPath path{};
    double yOffset{0.5 * Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"]};
    double lX{static_cast<double>(left->parentWidget()->x() + left->x() + left->width())};
    double lY{left->parentWidget()->y() + left->y() + yOffset};
    double rX{static_cast<double>(right->parentWidget()->x() + right->x())};
    double rY{right->parentWidget()->y() + right->y() + yOffset};
    path.moveTo(lX, lY);
    path.cubicTo(lX + Registry::getRegistry()->extrinsic->GUI->dimensions["NodePathSharpness"], lY, rX - Registry::getRegistry()->extrinsic->GUI->dimensions["NodePathSharpness"], rY, rX, rY);
    QPen pen{Registry::getRegistry()->extrinsic->GUI->palette["NodePath"], Registry::getRegistry()->extrinsic->GUI->dimensions["NodePathWidth"]};
    painter.setPen(pen);
    painter.drawPath(path);
}
