#include "Widgets/NodeEditor.hpp"

#include "NodeSystem/Node.hpp"
#include "Settings.hpp"

#include "Nodes/CanvasNode.hpp" // DEBUG

float NodeEditor::NodeContainer::padding{10};
float NodeEditor::NodeContainer::cornerRadius{10};
float NodeEditor::NodeContainer::borderWidth{2};
float NodeEditor::NodeContainer::headerHeight{30};

NodeEditor::NodeContainer::NodeContainer(NodeEditor* parent, Node* node) : QWidget(parent), node{node}
{
    resize(400, 200);
    inputs.push_back(new NodeConnectorLeft{this, CNVS->inputs[0], 50});
}

void NodeEditor::NodeContainer::paintEvent(QPaintEvent*)
{
    QPainter painter{this};
    painter.setRenderHint(QPainter::Antialiasing);
    QPainterPath border{};
    QPainterPath separator{};
    border.addRoundedRect(QRectF(padding - 0.5, padding - 0.5, width() - 2 * padding, height() - 2 * padding), cornerRadius, cornerRadius);
    QPen borderPen{Settings::getSettings()->extrinsic->palette["NodeBorder"], borderWidth};
    QPen separatorPen{Settings::getSettings()->extrinsic->palette["NodeHeaderSeparator"], borderWidth};
    QPen textPen{Settings::getSettings()->extrinsic->palette["NodeHeaderText"]};
    painter.setPen(borderPen);
    painter.fillPath(border, Settings::getSettings()->extrinsic->palette["NodeBackground"]);
    painter.drawPath(border);
    painter.setPen(separatorPen);
    painter.drawLine(padding + borderWidth, padding + borderWidth + headerHeight, width() - padding - borderWidth - 1, padding + borderWidth + headerHeight);
    painter.setPen(textPen);
    painter.drawText(2 * padding, padding + headerHeight - 8, QString::fromStdString(node->nodeName()));
}
