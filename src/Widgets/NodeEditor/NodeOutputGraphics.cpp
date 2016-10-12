#include "Widgets/NodeEditor.hpp"

#include "NodeSystem/NodeOutput.hpp"
#include "Registry.hpp"

NodeEditor::NodeOutputGraphics::NodeOutputGraphics(NodeGraphics* parent, NodeOutput* output, int y) : QWidget(parent), connections{}, output{output}
{
    resize(parent->width(), Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"]);
    move(0, y);
}

void NodeEditor::NodeOutputGraphics::paintEvent(QPaintEvent*)
{
    QPainter painter{this};
    painter.setRenderHint(QPainter::Antialiasing);
    QPainterPath border{};
    border.addEllipse(parentWidget()->width() - Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"], 0, Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"], Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"]);
    QPen borderPen{Registry::getRegistry()->extrinsic->GUI->palette["NodeConnectorBorder"], Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorBorder"]};
    QPen textPen{Registry::getRegistry()->extrinsic->GUI->palette["NodeConnectorText"]};
    painter.setPen(borderPen);
    painter.fillPath(border, Registry::getRegistry()->extrinsic->GUI->palette["NodeConnectorBackground"]);
    painter.drawPath(border);
    painter.setPen(textPen);
    int textWidth{painter.fontMetrics().width(QString::fromStdString(output->name))};
    painter.drawText(parentWidget()->width() - Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"] - textWidth - 5, Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"] - 5, QString::fromStdString(output->name));
}
