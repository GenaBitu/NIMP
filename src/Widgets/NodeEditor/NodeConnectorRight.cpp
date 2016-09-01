#include "Widgets/NodeEditor.hpp"

#include "NodeSystem/NodeOutput.hpp"
#include "Registry.hpp"

NodeEditor::NodeConnectorRight::NodeConnectorRight(NodeGraphics* parent, NodeOutput* output, float y) : QWidget(parent), output{output}
{
    resize(parent->width(), Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"]);
    move(0, y);
}

void NodeEditor::NodeConnectorRight::paintEvent(QPaintEvent*)
{
    // TODO: On the RIGHT
    QPainter painter{this};
    painter.setRenderHint(QPainter::Antialiasing);
    QPainterPath border{};
    border.addEllipse(0, 0, Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"], Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"]);
    QPen borderPen{Registry::getRegistry()->extrinsic->GUI->palette["NodeConnectorBorder"], 1};
    QPen textPen{Registry::getRegistry()->extrinsic->GUI->palette["NodeConnectorText"]};
    painter.setPen(borderPen);
    painter.fillPath(border, Registry::getRegistry()->extrinsic->GUI->palette["NodeConnectorBackground"]);
    painter.drawPath(border);
    painter.setPen(textPen);
    painter.drawText(Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"] + 5, Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"] - 4, QString::fromStdString(output->name));
}
