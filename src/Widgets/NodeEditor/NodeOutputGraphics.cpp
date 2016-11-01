#include "Widgets/NodeEditor/NodeOutputGraphics.hpp"

#include "NodeSystem/NodeOutput.hpp"
#include "Registry.hpp"
#include "Widgets/NodeEditor.hpp"

NodeOutputGraphics::NodeOutputGraphics(NodeGraphics* parent, NodeOutput* output, int y) : QWidget(parent), connections{}, output{output}, connector{new NodeIOConnector{this, parentWidget()->width() - Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"]}}
{
    resize(parent->width(), Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"]);
    move(0, y);
    QObject::connect(output, &NodeOutput::reconnected, this, &NodeOutputGraphics::reconnect);
}

void NodeOutputGraphics::connect()
{
    if(connections.empty())
    {
        NodeEditor* editor{dynamic_cast<NodeEditor*>(parentWidget()->parentWidget())};
        for(std::unordered_set<NodeInput*>::const_iterator it{output->getConnections().begin()}; it != output->getConnections().end(); it++)
        {
            NodeInputGraphics* inputConnector{nullptr};
            for(std::vector<NodeGraphics*>::iterator jt{editor->nodes.begin()}; jt != editor->nodes.end(); jt++)
            {
                for(std::vector<NodeInputGraphics*>::iterator kt{(*jt)->inputs.begin()}; kt != (*jt)->inputs.end(); kt++)
                {
                    if((*kt)->input == (*it))
                    {
                        inputConnector = *kt;
                    }
                }
            }
            if(inputConnector != nullptr)
            {
                new NodePath{editor, this, inputConnector};
            }
        }
    }
}

void NodeOutputGraphics::disconnect()
{
    for(std::unordered_set<NodePath*>::iterator it{connections.begin()}; it != connections.end();)
    {
        if((*it)->right->connection == (*it))
        {
            (*it)->right->connection = nullptr;
        }
        delete *it;
        connections.erase(it);
    }
    connections.clear();
}

void NodeOutputGraphics::reconnect()
{
    disconnect();
    connect();
}

void NodeOutputGraphics::paintEvent(QPaintEvent*)
{
    QPainter painter{this};
    painter.setRenderHint(QPainter::Antialiasing);
    QPen textPen{Registry::getRegistry()->extrinsic->GUI->palette["NodeConnectorText"]};
    painter.setPen(textPen);
    int textWidth{painter.fontMetrics().width(QString::fromStdString(output->name))};
    painter.drawText(parentWidget()->width() - Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"] - textWidth - 5, Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"] - 5, QString::fromStdString(output->name));
}
