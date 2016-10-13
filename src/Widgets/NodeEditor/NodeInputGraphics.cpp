#include "Widgets/NodeEditor.hpp"

#include "NodeSystem/NodeInput.hpp"
#include "Registry.hpp"

NodeEditor::NodeInputGraphics::NodeInputGraphics(NodeGraphics* parent, NodeInput* input, int y) : QWidget(parent), connection{}, input{input}
{
    resize(parent->width(), Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"]);
    move(0, y);
}

void NodeEditor::NodeInputGraphics::connect()
{
    if(connection == nullptr)
    {
        NodeOutput* nodeOutput{input->connection};
        NodeOutputGraphics* outputConnector;
        NodeEditor* editor{dynamic_cast<NodeEditor*>(parentWidget()->parentWidget())};
        for(std::vector<NodeGraphics*>::iterator it{editor->nodes.begin()}; it != editor->nodes.end(); it++)
        {
            for(std::vector<NodeOutputGraphics*>::iterator jt{(*it)->outputs.begin()}; jt != (*it)->outputs.end(); jt++)
            {
                if((*jt)->output == nodeOutput)
                {
                    outputConnector = *jt;
                }
            }
        }
        editor->paths.push_back(new NodePath{editor, outputConnector, this});
    }
}

void NodeEditor::NodeInputGraphics::disconnect()
{
    if(connection != nullptr)
    {
        std::vector<NodePath*> vec{connection->left->connections};
        vec.erase(std::remove(vec.begin(), vec.end(), connection), vec.end());
        delete connection;
        connection = nullptr;
    }
}

void NodeEditor::NodeInputGraphics::paintEvent(QPaintEvent*)
{
    QPainter painter{this};
    painter.setRenderHint(QPainter::Antialiasing);
    QPainterPath border{};
    border.addEllipse(0, 0, Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"], Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"]);
    QPen borderPen{Registry::getRegistry()->extrinsic->GUI->palette["NodeConnectorBorder"], Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorBorder"]};
    QPen textPen{Registry::getRegistry()->extrinsic->GUI->palette["NodeConnectorText"]};
    painter.setPen(borderPen);
    painter.fillPath(border, Registry::getRegistry()->extrinsic->GUI->palette["NodeConnectorBackground"]);
    painter.drawPath(border);
    painter.setPen(textPen);
    painter.drawText(Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"] + 5, Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"] - 5, QString::fromStdString(input->name));
}
