#include "include/Widgets/NodeEditor/NodeConnectorLeft.hpp"

NodeConnectorLeft::NodeConnectorLeft(QWidget* parent, int y) : QWidget(parent)
{
    resize(20, 20);
    move(0, y);
}

void NodeConnectorLeft::paintEvent(QPaintEvent*)
{
    QPainter painter{this};
    painter.setRenderHint(QPainter::Antialiasing);
    QPainterPath border{};
    border.addEllipse(0, 0, 20, 20);
    QPen borderPen{Qt::darkGray, 1};
    painter.setPen(borderPen);
    painter.fillPath(border, Qt::yellow);
    painter.drawPath(border);
}
