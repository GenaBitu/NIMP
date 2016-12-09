#include "Widgets/NodeEditor/NodePath.hpp"

#include "Registry.hpp"
#include "WidgetActions/States/ActionState.hpp"
#include "Widgets/NodeEditor.hpp"
#include "NodeSystem/Node.hpp"

NodePath::NodePath(NodeEditor* parent, NodeOutputGraphics* left, NodeInputGraphics* right) : Selectable(parent), left{left}, right{right}, path{}
{
    setFocusPolicy(Qt::ClickFocus);
    parent->paths.insert(this);
    (*state->palette)["path"] = std::make_tuple("NodePath", "NodePathActive");
    left->connections.insert(this);
    right->connection = this;
    reposition();
    show();
    lower();
}

void NodePath::reposition()
{
    resize(10000, 10000);
    double yOffset{0.5 * Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"]};
    double lX{static_cast<double>(left->parentWidget()->x() + left->x() + left->width())};
    double lY{left->parentWidget()->y() + left->y() + yOffset};
    double rX{static_cast<double>(right->parentWidget()->x() + right->x())};
    double rY{right->parentWidget()->y() + right->y() + yOffset};
    double sharpness{std::max(static_cast<double>(Registry::getRegistry()->extrinsic->GUI->dimensions["NodePathSharpness"]), 0.4f * (rX - lX))};
    delete path;
    path = new QPainterPath{};
    path->moveTo(lX, lY);
    path->cubicTo(lX + sharpness, lY, rX - sharpness, rY, rX, rY);
    QPainterPathStroker stroker;
    stroker.setWidth(Registry::getRegistry()->extrinsic->GUI->dimensions["NodePathClickableWidth"]);
    QPainterPath thick{stroker.createStroke(*path)};
    setMask(QPolygonF{thick.boundingRect()}.toPolygon());
    state->changeMask(&thick);
    update();
}

void NodePath::disconnect()
{
    Node::disconnect(left->output, right->input);
}

NodePath::~NodePath()
{
    NodeEditor* editor{dynamic_cast<NodeEditor*>(parentWidget())};
    if(editor != nullptr)
    {
        editor->paths.erase(this);
    }
    delete path;
}

void NodePath::keyPressEvent(QKeyEvent* event)
{
    if(event->key() == Registry::getRegistry()->extrinsic->GUI->keys["Delete"] and getState() == ActionWidget::State::SELECTED)
    {
        event->accept();
        disconnect();
    }
    else
    {
        event->ignore();
    }
}

void NodePath::paintEvent(QPaintEvent*)
{
    if(path != nullptr)
    {
        QPainter painter{this};
        painter.setRenderHint(QPainter::Antialiasing);
        QPen pen{state->getColour("path"), static_cast<double>(Registry::getRegistry()->extrinsic->GUI->dimensions["NodePathWidth"])};
        painter.setPen(pen);
        painter.drawPath(*path);
    }
}
