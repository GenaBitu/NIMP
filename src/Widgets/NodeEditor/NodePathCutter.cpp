#include "Widgets/NodeEditor/NodePathCutter.hpp"

#include "Widgets/NodeEditor.hpp"
#include "Registry.hpp"

NodePathCutter::NodePathCutter(NodeEditor* parent, QPoint origin) : Selectable{parent}, origin{origin}, path{}
{
    show();
    grabMouse();
    changeState(States::SELECTED);
}

NodePathCutter::~NodePathCutter()
{
    delete path;
}

void NodePathCutter::mouseMoveEvent(QMouseEvent* event)
{
    resize(10000, 10000);
    delete path;
    path = new QPainterPath{};
    path->moveTo(origin);
    path->lineTo(event->pos());
    update();
}

void NodePathCutter::mouseReleaseEvent(QMouseEvent*)
{
    if(path != nullptr)
    {
        NodeEditor* editor{dynamic_cast<NodeEditor*>(parentWidget())};
        if(editor == nullptr)
		{
			// TODO: DIE HORRIBLY IN FLAMES
			return;
		}
        for(std::unordered_set<NodePath*>::iterator it{editor->paths.begin()}; it != editor->paths.end(); it++)
        {
            if(path->intersects(*(*it)->path))
            {
                (*it)->disconnect();
	            it = editor->paths.begin();
            }
        }
    }
    releaseMouse();
    delete this;
}

void NodePathCutter::paintEvent(QPaintEvent*)
{
    if(path != nullptr)
    {
        QPainter painter{this};
        painter.setRenderHint(QPainter::Antialiasing);
        QPen pen{Registry::getRegistry()->extrinsic->GUI->palette["NodePathCutter"], static_cast<double>(Registry::getRegistry()->extrinsic->GUI->dimensions["NodePathCutterWidth"])};
        painter.setPen(pen);
        painter.drawPath(*path);
    }
}
