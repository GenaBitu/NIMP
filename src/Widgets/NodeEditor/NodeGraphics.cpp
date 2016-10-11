#include "Widgets/NodeEditor.hpp"

#include "NodeSystem/Node.hpp"
#include "Registry.hpp"
#include "WidgetActions/States/ActionState.hpp"

NodeEditor::NodeGraphics::NodeGraphics(NodeEditor* parent, Node* node) : Draggable(parent), node{node}
{
    resize(200, height());
    updateConnections();
    move(node->x, node->y);
    (*state->palette)["border"] = std::make_tuple("NodeBorder", "NodeBorderActive");
}

void NodeEditor::NodeGraphics::buildPaths()
{
    for(std::vector<NodeConnectorLeft*>::iterator it{inputs.begin()}; it != inputs.end(); it++)
    {
        (*it)->buildPath();
    }
}

void NodeEditor::NodeGraphics::mouseReleaseEvent(QMouseEvent* event)
{
    Draggable::mouseReleaseEvent(event);
    node->x = x();
    node->y = y();
}

void NodeEditor::NodeGraphics::paintEvent(QPaintEvent*)
{
    //updateConnections();
    QPainter painter{this};
    painter.setRenderHint(QPainter::Antialiasing);
    QPainterPath border{};
    QPainterPath separator{};
    border.addRoundedRect(QRectF(Registry::getRegistry()->extrinsic->GUI->dimensions["NodeMargin"] - 0.5, Registry::getRegistry()->extrinsic->GUI->dimensions["NodeMargin"] - 0.5, width() - 2 * Registry::getRegistry()->extrinsic->GUI->dimensions["NodeMargin"], height() - 2 * Registry::getRegistry()->extrinsic->GUI->dimensions["NodeMargin"]), Registry::getRegistry()->extrinsic->GUI->dimensions["NodeCornerRadius"], Registry::getRegistry()->extrinsic->GUI->dimensions["NodeCornerRadius"]);
    state->changeMask(&border);
    QPen borderPen{state->getColour("border"), Registry::getRegistry()->extrinsic->GUI->dimensions["NodeBorderWidth"]};
    QPen separatorPen{Registry::getRegistry()->extrinsic->GUI->palette["NodeHeaderSeparator"], Registry::getRegistry()->extrinsic->GUI->dimensions["NodeHeaderSeparatorHeight"]};
    QPen textPen{Registry::getRegistry()->extrinsic->GUI->palette["NodeHeaderText"]};
    painter.setPen(borderPen);
    painter.fillPath(border, Registry::getRegistry()->extrinsic->GUI->palette["NodeBackground"]);
    painter.drawPath(border);
    painter.setPen(separatorPen);
    painter.drawLine(Registry::getRegistry()->extrinsic->GUI->dimensions["NodeMargin"] + Registry::getRegistry()->extrinsic->GUI->dimensions["NodeBorderWidth"], Registry::getRegistry()->extrinsic->GUI->dimensions["NodeMargin"] + Registry::getRegistry()->extrinsic->GUI->dimensions["NodeBorderWidth"] + Registry::getRegistry()->extrinsic->GUI->dimensions["NodeHeaderHeight"], width() - Registry::getRegistry()->extrinsic->GUI->dimensions["NodeMargin"] - Registry::getRegistry()->extrinsic->GUI->dimensions["NodeBorderWidth"] - 1, Registry::getRegistry()->extrinsic->GUI->dimensions["NodeMargin"] + Registry::getRegistry()->extrinsic->GUI->dimensions["NodeBorderWidth"] + Registry::getRegistry()->extrinsic->GUI->dimensions["NodeHeaderHeight"]);
    painter.setPen(textPen);
    painter.drawText(2 * Registry::getRegistry()->extrinsic->GUI->dimensions["NodeMargin"], Registry::getRegistry()->extrinsic->GUI->dimensions["NodeMargin"] + Registry::getRegistry()->extrinsic->GUI->dimensions["NodeHeaderHeight"] - 8, QString::fromStdString(node->nodeName()));
    repaintConnections();
}

void NodeEditor::NodeGraphics::updateConnections()
{
    inputs.clear();
    outputs.clear();
    int height{static_cast<int>(Registry::getRegistry()->extrinsic->GUI->dimensions["NodeMargin"] + Registry::getRegistry()->extrinsic->GUI->dimensions["NodeBorderWidth"] + Registry::getRegistry()->extrinsic->GUI->dimensions["NodeHeaderHeight"] + 0.5)};
    for(std::vector<NodeOutput*>::iterator it{node->outputs.begin()}; it != node->outputs.end(); it++)
    {
        height += Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorSpacing"];
        outputs.push_back(new NodeConnectorRight{this, *it, height});
        height += outputs.back()->height();
    }
    for(std::vector<NodeInput*>::iterator it{node->inputs.begin()}; it != node->inputs.end(); it++)
    {
        height += Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorSpacing"];
        inputs.push_back(new NodeConnectorLeft{this, *it, height});
        height += inputs.back()->height();
    }
    height += Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorSpacing"] + Registry::getRegistry()->extrinsic->GUI->dimensions["NodeMargin"];
    resize(width(), height);
}

void NodeEditor::NodeGraphics::repaintConnections()
{
    for(std::vector<NodeConnectorLeft*>::iterator it{inputs.begin()}; it != inputs.end(); it++)
    {
        if((*it)->path != nullptr)
        {
            (*it)->path->update();
        }
    }
    for(std::vector<NodeConnectorRight*>::iterator it{outputs.begin()}; it != outputs.end(); it++)
    {
        if((*it)->path != nullptr)
        {
            (*it)->path->update();
        }
    }
}
