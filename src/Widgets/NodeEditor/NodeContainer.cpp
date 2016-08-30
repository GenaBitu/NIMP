#include "Widgets/NodeEditor.hpp"

#include "NodeSystem/Node.hpp"
#include "Settings.hpp"

NodeEditor::NodeContainer::NodeContainer(NodeEditor* parent, Node* node) : QWidget(parent), node{node}
{
    float height{updateConnections()};
    resize(width(), height);
}

void NodeEditor::NodeContainer::paintEvent(QPaintEvent*)
{
    QPainter painter{this};
    painter.setRenderHint(QPainter::Antialiasing);
    QPainterPath border{};
    QPainterPath separator{};
    border.addRoundedRect(QRectF(Settings::getSettings()->extrinsic->GUI->dimensions["NodeMargin"] - 0.5, Settings::getSettings()->extrinsic->GUI->dimensions["NodeMargin"] - 0.5, width() - 2 * Settings::getSettings()->extrinsic->GUI->dimensions["NodeMargin"], height() - 2 * Settings::getSettings()->extrinsic->GUI->dimensions["NodeMargin"]), Settings::getSettings()->extrinsic->GUI->dimensions["NodeCornerRadius"], Settings::getSettings()->extrinsic->GUI->dimensions["NodeCornerRadius"]);
    QPen borderPen{Settings::getSettings()->extrinsic->GUI->palette["NodeBorder"], Settings::getSettings()->extrinsic->GUI->dimensions["NodeBorderWidth"]};
    QPen separatorPen{Settings::getSettings()->extrinsic->GUI->palette["NodeHeaderSeparator"], Settings::getSettings()->extrinsic->GUI->dimensions["NodeHeaderSeparatorHeight"]};
    QPen textPen{Settings::getSettings()->extrinsic->GUI->palette["NodeHeaderText"]};
    painter.setPen(borderPen);
    painter.fillPath(border, Settings::getSettings()->extrinsic->GUI->palette["NodeBackground"]);
    painter.drawPath(border);
    painter.setPen(separatorPen);
    painter.drawLine(Settings::getSettings()->extrinsic->GUI->dimensions["NodeMargin"] + Settings::getSettings()->extrinsic->GUI->dimensions["NodeBorderWidth"], Settings::getSettings()->extrinsic->GUI->dimensions["NodeMargin"] + Settings::getSettings()->extrinsic->GUI->dimensions["NodeBorderWidth"] + Settings::getSettings()->extrinsic->GUI->dimensions["NodeHeaderHeight"], width() - Settings::getSettings()->extrinsic->GUI->dimensions["NodeMargin"] - Settings::getSettings()->extrinsic->GUI->dimensions["NodeBorderWidth"] - 1, Settings::getSettings()->extrinsic->GUI->dimensions["NodeMargin"] + Settings::getSettings()->extrinsic->GUI->dimensions["NodeBorderWidth"] + Settings::getSettings()->extrinsic->GUI->dimensions["NodeHeaderHeight"]);
    painter.setPen(textPen);
    painter.drawText(2 * Settings::getSettings()->extrinsic->GUI->dimensions["NodeMargin"], Settings::getSettings()->extrinsic->GUI->dimensions["NodeMargin"] + Settings::getSettings()->extrinsic->GUI->dimensions["NodeHeaderHeight"] - 8, QString::fromStdString(node->nodeName()));
}

float NodeEditor::NodeContainer::updateConnections()
{
    inputs.clear();
    float height{Settings::getSettings()->extrinsic->GUI->dimensions["NodeMargin"] + Settings::getSettings()->extrinsic->GUI->dimensions["NodeBorderWidth"] + Settings::getSettings()->extrinsic->GUI->dimensions["NodeHeaderHeight"]};
    for(auto it{node->outputs.begin()}; it != node->outputs.end(); it++)
    {
        height += Settings::getSettings()->extrinsic->GUI->dimensions["NodeConnectorSpacing"];
        outputs.push_back(new NodeConnectorRight{this, *it, height});
        height += outputs.back()->height();
    }
    for(auto it{node->inputs.begin()}; it != node->inputs.end(); it++)
    {
        height += Settings::getSettings()->extrinsic->GUI->dimensions["NodeConnectorSpacing"];
        inputs.push_back(new NodeConnectorLeft{this, *it, height});
        height += inputs.back()->height();
    }
    height += Settings::getSettings()->extrinsic->GUI->dimensions["NodeConnectorSpacing"] + Settings::getSettings()->extrinsic->GUI->dimensions["NodeMargin"];
    return height;
}
