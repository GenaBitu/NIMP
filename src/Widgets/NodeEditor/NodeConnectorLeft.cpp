#include "include/Widgets/NodeEditor/NodeConnectorLeft.hpp"

#include "include/NodeSystem/NodeInput.hpp"

NodeConnectorLeft::NodeConnectorLeft(QWidget* parent, NodeInput* input, int y) : QWidget(parent), input{input}
{
    resize(200, 20);
    move(0, y);
}

void NodeConnectorLeft::paintEvent(QPaintEvent*)
{
    QPainter painter{this};
    painter.setRenderHint(QPainter::Antialiasing);
    QPainterPath border{};
    border.addEllipse(0, 0, 20, 20);
    QPen borderPen{Qt::darkGray, 1};
    QPen textPen{Qt::black};
    painter.setPen(borderPen);
    painter.fillPath(border, Qt::yellow);
    painter.drawPath(border);
    painter.setPen(textPen);
    painter.drawText(25, 16, QString::fromStdString(input->name));
}
