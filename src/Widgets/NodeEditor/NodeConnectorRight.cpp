#include "Widgets/NodeEditor.hpp"

#include "NodeSystem/NodeOutput.hpp"
#include "Settings.hpp"

NodeEditor::NodeConnectorRight::NodeConnectorRight(NodeContainer* parent, NodeOutput* output, float y) : QWidget(parent), output{output}
{
    resize(parent->width(), Settings::getSettings()->extrinsic->GUI->dimensions["NodeConnectorDiameter"]);
    move(0, y);
}

void NodeEditor::NodeConnectorRight::paintEvent(QPaintEvent*)
{
    // TODO: On the RIGHT
    QPainter painter{this};
    painter.setRenderHint(QPainter::Antialiasing);
    QPainterPath border{};
    border.addEllipse(0, 0, Settings::getSettings()->extrinsic->GUI->dimensions["NodeConnectorDiameter"], Settings::getSettings()->extrinsic->GUI->dimensions["NodeConnectorDiameter"]);
    QPen borderPen{Settings::getSettings()->extrinsic->GUI->palette["NodeConnectorBorder"], 1};
    QPen textPen{Settings::getSettings()->extrinsic->GUI->palette["NodeConnectorText"]};
    painter.setPen(borderPen);
    painter.fillPath(border, Settings::getSettings()->extrinsic->GUI->palette["NodeConnectorBackground"]);
    painter.drawPath(border);
    painter.setPen(textPen);
    painter.drawText(Settings::getSettings()->extrinsic->GUI->dimensions["NodeConnectorDiameter"] + 5, Settings::getSettings()->extrinsic->GUI->dimensions["NodeConnectorDiameter"] - 4, QString::fromStdString(output->name));
}
