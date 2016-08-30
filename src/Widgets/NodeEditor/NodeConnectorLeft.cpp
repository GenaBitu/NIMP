#include "Widgets/NodeEditor.hpp"

#include "NodeSystem/NodeInput.hpp"
#include "Settings.hpp"

NodeEditor::NodeConnectorLeft::NodeConnectorLeft(QWidget* parent, NodeInput* input, int y) : QWidget(parent), input{input}
{
    resize(200, Settings::getSettings()->extrinsic->GUI->dimensions["NodeConnectorDiameter"]);
    move(0, y);
}

void NodeEditor::NodeConnectorLeft::paintEvent(QPaintEvent*)
{
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
    painter.drawText(Settings::getSettings()->extrinsic->GUI->dimensions["NodeConnectorDiameter"] + 5, Settings::getSettings()->extrinsic->GUI->dimensions["NodeConnectorDiameter"] - 4, QString::fromStdString(input->name));
}
