#include "Widgets/NodeEditor/NodeInputGraphics.hpp"

#include "NodeSystem/NodeOutput.hpp"
#include "NodeSystem/NodeInput.hpp"
#include "Registry.hpp"
#include "Widgets/NodeEditor.hpp"

NodeInputGraphics::NodeInputGraphics(NodeGraphics* parent, NodeInput* input, int y) : QWidget(parent), connection{}, input{input}, connector{new NodeIOConnector{this}}
{
    resize(parent->width(), Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"]);
    move(0, y);
}

void NodeInputGraphics::connect()
{
    if(connection == nullptr)
    {
        const NodeOutput* nodeOutput{input->getConnection()};
        NodeOutputGraphics* outputConnector{nullptr};
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
        if(outputConnector != nullptr)
        {
            editor->paths.push_back(new NodePath{editor, outputConnector, this});
        }
    }
}

void NodeInputGraphics::disconnect()
{
    if(connection != nullptr)
    {
        std::vector<NodePath*> vec{connection->left->connections};
        vec.erase(std::remove(vec.begin(), vec.end(), connection), vec.end());
        delete connection;
        connection = nullptr;
    }
}

void NodeInputGraphics::paintEvent(QPaintEvent*)
{
    QPainter painter{this};
    painter.setRenderHint(QPainter::Antialiasing);
    QPen textPen{Registry::getRegistry()->extrinsic->GUI->palette["NodeConnectorText"]};
    painter.setPen(textPen);
    painter.drawText(Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"] + 5, Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"] - 5, QString::fromStdString(input->name));
}
