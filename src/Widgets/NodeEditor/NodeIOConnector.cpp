#include "Widgets/NodeEditor/NodeIOConnector.hpp"

#include "Registry.hpp"
#include "Widgets/NodeEditor/NodeInputGraphics.hpp"
#include "Widgets/NodeEditor/NodeOutputGraphics.hpp"

NodeIOConnector::NodeIOConnector(NodeInputGraphics* parent, float x, float y) : QWidget(parent)
{
    init(x, y);
}

NodeIOConnector::NodeIOConnector(NodeOutputGraphics* parent, float x, float y) : QWidget(parent)
{
    init(x, y);
}

void NodeIOConnector::paintEvent(QPaintEvent*)
{
    QPainter painter{this};
    painter.setRenderHint(QPainter::Antialiasing);
    QPainterPath border{};
    border.addEllipse(0, 0, Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"], Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"]);
    QPen borderPen{Registry::getRegistry()->extrinsic->GUI->palette["NodeConnectorBorder"], Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorBorder"]};
    painter.setPen(borderPen);
    painter.fillPath(border, Registry::getRegistry()->extrinsic->GUI->palette["NodeConnectorBackground"]);
    painter.drawPath(border);
}

void NodeIOConnector::init(float x, float y)
{
    move(x, y);
}
