#include "Widgets/NodeEditor/NodeIOConnector.hpp"

#include "Registry.hpp"
#include "Widgets/NodeEditor.hpp"

NodeIOConnector::NodeIOConnector(NodeInputGraphics* parent, int x, int y) : QWidget(parent)
{
    init(x, y);
}

NodeIOConnector::NodeIOConnector(NodeOutputGraphics* parent, int x, int y) : QWidget(parent)
{
    init(x, y);
}

void NodeIOConnector::mousePressEvent(QMouseEvent*)
{
    NodeEditor* editor{dynamic_cast<NodeEditor*>(parentWidget()->parentWidget()->parentWidget())};
    NodeInputGraphics* input{dynamic_cast<NodeInputGraphics*>(parentWidget())};
    if(input != nullptr)
    {
        new TempPath{editor, input};
    }
    NodeOutputGraphics* output{dynamic_cast<NodeOutputGraphics*>(parentWidget())};
    if(output != nullptr)
    {
        new TempPath{editor, output};
    }
}

void NodeIOConnector::paintEvent(QPaintEvent*)
{
    QPainter painter{this};
    painter.setRenderHint(QPainter::Antialiasing);
    QPainterPath border{};
    border.addEllipse(0, 0, Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"], Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"]);
    QPen borderPen{Registry::getRegistry()->extrinsic->GUI->palette["NodeConnectorBorder"], static_cast<double>(Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorBorder"])};
    painter.setPen(borderPen);
    painter.fillPath(border, Registry::getRegistry()->extrinsic->GUI->palette["NodeConnectorBackground"]);
    painter.drawPath(border);
}

void NodeIOConnector::init(int x, int y)
{
    move(x, y);
    resize(Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"], Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"]);
    QPainterPath path{};
    path.addEllipse(-1, -1, Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"] + 1, Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"] + 1);
    setMask(path.toFillPolygon().toPolygon());
}
