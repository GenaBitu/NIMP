#include "Widgets/NodeEditor/NodeGraphics.hpp"

#include "NodeSystem/Node.hpp"
#include "Registry.hpp"
#include "WidgetActions/States/ActionState.hpp"
#include "Widgets/NodeEditor.hpp"

const int NodeGraphics::headerHeight{static_cast<int>(Registry::getRegistry()->extrinsic->GUI->dimensions["NodeMargin"] + Registry::getRegistry()->extrinsic->GUI->dimensions["NodeBorderWidth"] + Registry::getRegistry()->extrinsic->GUI->dimensions["NodeHeaderHeight"])};
const int NodeGraphics::footerHeight{static_cast<int>(Registry::getRegistry()->extrinsic->GUI->dimensions["NodeMargin"] + Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorSpacing"])};

NodeGraphics::NodeGraphics(NodeEditor* parent, Node* node) : Draggable(parent), inputs{}, outputs{}, interfaces{}, node{node}, interfaceHeight{}, connectionHeight{}
{
    setFocusPolicy(Qt::ClickFocus);
    resize(200, height());
    move(node->getPos());
    show();
    (*state->palette)["border"] = std::make_tuple("NodeBorder", "NodeBorderActive");
    QObject::connect(node, &Node::moved, this, &NodeGraphics::reposition);
    QObject::connect(node, &Node::deleted, this, &NodeGraphics::destruct);
}

void NodeGraphics::addInterfaces()
{
    interfaceHeight = 0;
    for(std::vector<NodeInterface*>::iterator it{node->interfaces.begin()}; it != node->interfaces.end(); it++)
    {
        interfaceHeight += Registry::getRegistry()->extrinsic->GUI->dimensions["NodeInterfaceSpacing"];
        NodeInterfaceGraphics* newItem{NodeInterfaceGraphics::interfaceFactory(this, *it, headerHeight + interfaceHeight)};
        interfaces.push_back(newItem);
        interfaceHeight += newItem->height();
    }
    rebuildConnections();
}

void NodeGraphics::addConnections()
{
    connectionHeight = 0;
    for(std::vector<NodeInput*>::iterator it{node->inputs.begin()}; it != node->inputs.end(); it++)
    {
        connectionHeight += Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorSpacing"];
        NodeInputGraphics* newItem{new NodeInputGraphics{this, *it, headerHeight + interfaceHeight + connectionHeight}};
        inputs.push_back(newItem);
        newItem->connect();
        connectionHeight += newItem->height();
    }
    for(std::vector<NodeOutput*>::iterator it{node->outputs.begin()}; it != node->outputs.end(); it++)
    {
        connectionHeight += Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorSpacing"];
        NodeOutputGraphics* newItem{new NodeOutputGraphics{this, *it, headerHeight + interfaceHeight + connectionHeight}};
        outputs.push_back(newItem);
        newItem->connect();
        connectionHeight += newItem->height();
    }
    resize(width(), headerHeight + interfaceHeight + connectionHeight + footerHeight);
    reMask();
}

void NodeGraphics::rebuildInterfaces()
{
    removeInterfaces();
    addInterfaces();
}

void NodeGraphics::rebuildConnections()
{
    removeConnections();
    addConnections();
}

void NodeGraphics::connect(NodeOutputGraphics* left, NodeInputGraphics* right)
{
    Node::connect(left->output, right->input);
}

NodeGraphics::~NodeGraphics()
{
    NodeEditor* editor{dynamic_cast<NodeEditor*>(parentWidget())};
    if(editor != nullptr)
    {
        std::vector<NodeGraphics*>& vec{editor->nodes};
        vec.erase(std::remove(vec.begin(), vec.end(), this), vec.end());
    }
}

void NodeGraphics::reposition()
{
    move(node->getPos());
}

void NodeGraphics::destruct()
{
    delete this;
}

void NodeGraphics::keyPressEvent(QKeyEvent* event)
{
    if(event->key() == Registry::getRegistry()->extrinsic->keys["Delete"] and getState() == ActionWidget::States::SELECTED)
    {
        event->accept();
        deleteNode();
    }
    else
    {
        event->ignore();
    }
}

void NodeGraphics::moveEvent(QMoveEvent*)
{
    reMask();
    updateConnections();
}

void NodeGraphics::mouseReleaseEvent(QMouseEvent* event)
{
    Draggable::mouseReleaseEvent(event);
    node->setPos(pos());
}

void NodeGraphics::paintEvent(QPaintEvent*)
{
    QPainter painter{this};
    painter.setRenderHint(QPainter::Antialiasing);
    QPainterPath border{};
    QPainterPath separator{};
    border.addRoundedRect(QRectF(Registry::getRegistry()->extrinsic->GUI->dimensions["NodeMargin"] - 0.5, Registry::getRegistry()->extrinsic->GUI->dimensions["NodeMargin"] - 0.5, width() - 2 * Registry::getRegistry()->extrinsic->GUI->dimensions["NodeMargin"], height() - 2 * Registry::getRegistry()->extrinsic->GUI->dimensions["NodeMargin"]), Registry::getRegistry()->extrinsic->GUI->dimensions["NodeCornerRadius"], Registry::getRegistry()->extrinsic->GUI->dimensions["NodeCornerRadius"]);
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
}

void NodeGraphics::reMask()
{
    QPainterPath border{};
    border.addRoundedRect(QRectF(Registry::getRegistry()->extrinsic->GUI->dimensions["NodeMargin"] - 0.5, Registry::getRegistry()->extrinsic->GUI->dimensions["NodeMargin"] - 0.5, width() - 2 * Registry::getRegistry()->extrinsic->GUI->dimensions["NodeMargin"], height() - 2 * Registry::getRegistry()->extrinsic->GUI->dimensions["NodeMargin"]), Registry::getRegistry()->extrinsic->GUI->dimensions["NodeCornerRadius"], Registry::getRegistry()->extrinsic->GUI->dimensions["NodeCornerRadius"]);
    state->changeMask(&border);
}

void NodeGraphics::removeInterfaces()
{
    for(std::vector<NodeInterfaceGraphics*>::iterator it{interfaces.begin()}; it != interfaces.end();)
    {
        delete (*it);
        it = interfaces.erase(it);
    }
    interfaceHeight = 0;
}

void NodeGraphics::removeConnections()
{
    for(std::vector<NodeInputGraphics*>::iterator it{inputs.begin()}; it != inputs.end();)
    {
        (*it)->disconnect();
        delete (*it);
        it = inputs.erase(it);
    }
    for(std::vector<NodeOutputGraphics*>::iterator it{outputs.begin()}; it != outputs.end();)
    {
        (*it)->disconnect();
        delete (*it);
        it = outputs.erase(it);
    }
    connectionHeight = 0;
}

void NodeGraphics::updateConnections()
{
    for(std::vector<NodeInputGraphics*>::iterator it{inputs.begin()}; it != inputs.end(); it++)
    {
        if((*it)->connection != nullptr)
        {
            (*it)->connection->reposition();
        }
    }
    for(std::vector<NodeOutputGraphics*>::iterator it{outputs.begin()}; it != outputs.end(); it++)
    {
        for(std::unordered_set<NodePath*>::iterator jt{(*it)->connections.begin()}; jt != (*it)->connections.end(); jt++)
        {
            (*jt)->reposition();
        }
    }
}

void NodeGraphics::deleteNode()
{
    delete node;
}
