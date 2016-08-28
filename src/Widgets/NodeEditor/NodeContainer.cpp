#include "include/Widgets/NodeEditor/NodeContainer.hpp"

#include "include/Widgets/NodeEditor/NodeOutline.hpp"

int NodeContainer::padding{10};

NodeContainer::NodeContainer(Node* node) : QWidget(), node{node}, outline{new NodeOutline{}}
{

}

void NodeContainer::paintEvent(QPaintEvent*)
{
    QPainter painter{this};
    painter.setRenderHint(QPainter::Antialiasing);
    QPainterPath path{};
    path.addRoundedRect(QRectF(padding - 0.5, padding - 0.5, 100, 40), 10, 10);
    QPen pen{Qt::black, 2};
    painter.setPen(pen);
    painter.fillPath(path, Qt::gray);
    painter.drawPath(path);
}
