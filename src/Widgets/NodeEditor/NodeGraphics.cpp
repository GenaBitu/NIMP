#include "Widgets/NodeEditor/NodeGraphics.hpp"

#include "NodeSystem/Node.hpp"
#include "Registry.hpp"
#include "WidgetActions/States/ActionState.hpp"
#include "Widgets/NodeEditor.hpp"

NodeGraphics::NodeGraphics(NodeEditor* parent, Node* node) : Draggable(parent), inputs{}, outputs{}, node{node}
{
    setFocusPolicy(Qt::ClickFocus);
    resize(200, height());
    move(node->getPos());
    show();
    (*state->palette)["border"] = std::make_tuple("NodeBorder", "NodeBorderActive");
    QObject::connect(node, &Node::moved, this, &NodeGraphics::reposition);
    QObject::connect(node, &Node::deleted, this, &NodeGraphics::destruct);
}

void NodeGraphics::reposition()
{
    move(node->getPos());
}

void NodeGraphics::destruct()
{
    removeConnections();
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

void NodeGraphics::mouseReleaseEvent(QMouseEvent* event)
{
    Draggable::mouseReleaseEvent(event);
    node->setPos(pos());
}

void NodeGraphics::moveEvent(QMoveEvent*)
{
    reMask();
    updateConnections();
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
}

void NodeGraphics::addConnections()
{
    int height{static_cast<int>(Registry::getRegistry()->extrinsic->GUI->dimensions["NodeMargin"] + Registry::getRegistry()->extrinsic->GUI->dimensions["NodeBorderWidth"] + Registry::getRegistry()->extrinsic->GUI->dimensions["NodeHeaderHeight"] + 0.5)};
    for(std::vector<NodeInput*>::iterator it{node->inputs.begin()}; it != node->inputs.end(); it++)
    {
        height += Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorSpacing"];
        NodeInputGraphics* newItem{new NodeInputGraphics{this, *it, height}};
        inputs.push_back(newItem);
        newItem->connect();
        height += inputs.back()->height();
    }
    for(std::vector<NodeOutput*>::iterator it{node->outputs.begin()}; it != node->outputs.end(); it++)
    {
        height += Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorSpacing"];
        NodeOutputGraphics* newItem{new NodeOutputGraphics{this, *it, height}};
        outputs.push_back(newItem);
        newItem->connect();
        height += outputs.back()->height();
    }
    height += Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorSpacing"] + Registry::getRegistry()->extrinsic->GUI->dimensions["NodeMargin"];
    resize(width(), height);
    reMask();
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
