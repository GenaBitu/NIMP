#include "include/Widgets/NodeEditor/NodeContainer.hpp"

#include "include/NodeSystem/Node.hpp"

float NodeContainer::padding{10};
float NodeContainer::cornerRadius{10};
float NodeContainer::borderWidth{2};
float NodeContainer::headerHeight{30};

NodeContainer::NodeContainer(Node* node) : QWidget(), node{node}
{

}

void NodeContainer::paintEvent(QPaintEvent*)
{
    QPainter painter{this};
    painter.setRenderHint(QPainter::Antialiasing);
    QPainterPath border{};
    QPainterPath separator{};
    border.addRoundedRect(QRectF(padding - 0.5, padding - 0.5, width() - 2 * padding, height() - 2 * padding), cornerRadius, cornerRadius);
    QPen borderPen{Qt::black, borderWidth};
    QPen separatorPen{Qt::darkGray, borderWidth};
    QPen textPen{Qt::black};
    painter.setPen(borderPen);
    painter.fillPath(border, Qt::gray);
    painter.drawPath(border);
    painter.setPen(separatorPen);
    painter.drawLine(padding + borderWidth, padding + borderWidth + headerHeight, width() - padding - borderWidth - 1, padding + borderWidth + headerHeight);
    painter.setPen(textPen);
    painter.drawText(2 * padding, padding + headerHeight - 8, QString::fromStdString(node->nodeName()));
}
