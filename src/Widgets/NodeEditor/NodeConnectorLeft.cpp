#include "Widgets/NodeEditor.hpp"

#include "NodeSystem/NodeInput.hpp"
#include "Registry.hpp"

NodeEditor::NodeConnectorLeft::NodeConnectorLeft(NodeGraphics* parent, NodeInput* input, int y) : QWidget(parent), path{}, input{input}
{
    resize(parent->width(), Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"]);
    move(0, y);
}

void NodeEditor::NodeConnectorLeft::buildPath()
{
    NodeOutput* nodeOutput{input->connection};
    NodeConnectorRight* outputConnector;
    NodeEditor* editor{dynamic_cast<NodeEditor*>(parentWidget()->parentWidget())};
    for(std::vector<NodeGraphics*>::iterator it{editor->nodes.begin()}; it != editor->nodes.end(); it++)
    {
        for(std::vector<NodeConnectorRight*>::iterator jt{(*it)->outputs.begin()}; jt != (*it)->outputs.end(); jt++)
        {
            if((*jt)->output == nodeOutput)
            {
                outputConnector = *jt;
            }
        }
    }
    editor->paths.push_back(new NodePath{editor, outputConnector, this});
}

void NodeEditor::NodeConnectorLeft::paintEvent(QPaintEvent*)
{
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
    painter.drawText(Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"] + 5, Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"] - 5, QString::fromStdString(input->name));
}
