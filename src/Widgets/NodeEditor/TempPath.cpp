#include "Widgets/NodeEditor/TempPath.hpp"

#include "Registry.hpp"
#include "Widgets/NodeEditor.hpp"

TempPath::TempPath(NodeEditor* parent, NodeInputGraphics* right) : Selectable{parent}, left{nullptr}, right{right}, path{}
{
    show();
    grabMouse();
    changeState(States::SELECTED);
    lower();
}

TempPath::TempPath(NodeEditor* parent, NodeOutputGraphics* left) : Selectable{parent}, left{left}, right{nullptr}, path{}
{
    show();
    grabMouse();
    changeState(States::SELECTED);
    lower();
}

TempPath::~TempPath()
{
    delete path;
}

void TempPath::mouseMoveEvent(QMouseEvent* event)
{
    resize(10000, 10000);
    double yOffset{0.5 * Registry::getRegistry()->extrinsic->GUI->dimensions["NodeConnectorDiameter"]};
    double lX, lY, rX, rY;
    if(left != nullptr)
    {
        lX = static_cast<double>(left->parentWidget()->x() + left->x() + left->width());
        lY = left->parentWidget()->y() + left->y() + yOffset;
    }
    else
    {
        lX = event->x();
        lY = event->y();
    }
    if(right != nullptr)
    {
        rX = static_cast<double>(right->parentWidget()->x() + right->x());
        rY = right->parentWidget()->y() + right->y() + yOffset;
    }
    else
    {
        rX = event->x();
        rY = event->y();
    }
    double sharpness{std::max(static_cast<double>(Registry::getRegistry()->extrinsic->GUI->dimensions["NodePathSharpness"]), 0.4f * (rX - lX))};
    delete path;
    path = new QPainterPath{};
    path->moveTo(lX, lY);
    path->cubicTo(lX + sharpness, lY, rX - sharpness, rY, rX, rY);
    update();
}

void TempPath::mouseReleaseEvent(QMouseEvent* event)
{
    releaseMouse();
    NodeEditor* editor{dynamic_cast<NodeEditor*>(parentWidget())};
    if(editor == nullptr)
	{
		// TODO: DIE HORRIBLY IN FLAMES
		return;
	}
	NodeOutputGraphics* leftConnector{nullptr};
	NodeInputGraphics* rightConnector{nullptr};
    for(std::vector<NodeGraphics*>::iterator it{editor->nodes.begin()}; it != editor->nodes.end(); ++it)
    {
		for(std::vector<NodeOutputGraphics*>::iterator jt{(*it)->outputs.begin()}; jt != (*it)->outputs.end(); ++jt)
		{
			if((*jt)->connector->mask().contains((*jt)->connector->mapFromGlobal(event->globalPos())))
			{
				leftConnector = *jt;
				break;
			}
		}
		for(std::vector<NodeInputGraphics*>::iterator jt{(*it)->inputs.begin()}; jt != (*it)->inputs.end(); ++jt)
		{
			if((*jt)->connector->mask().contains((*jt)->connector->mapFromGlobal(event->globalPos())))
			{
				rightConnector = *jt;
				break;
            }
        }
    }
    if((left != nullptr) and (rightConnector != nullptr))
    {
        NodeGraphics::connect(left, rightConnector);
    }
	else if((leftConnector != nullptr) and (right != nullptr))
	{
		NodeGraphics::connect(leftConnector, right);
	}
	else if((right != nullptr) and (rightConnector != nullptr) and (right->connection != nullptr))
    {
		NodeGraphics::connect(right->connection->left, rightConnector);
    }
    delete this;
}

void TempPath::paintEvent(QPaintEvent*)
{
    if(path != nullptr)
    {
        QPainter painter{this};
        painter.setRenderHint(QPainter::Antialiasing);
        QPen pen{Registry::getRegistry()->extrinsic->GUI->palette["NodePathActive"], static_cast<double>(Registry::getRegistry()->extrinsic->GUI->dimensions["NodePathWidth"])};
        painter.setPen(pen);
        painter.drawPath(*path);
    }
}
