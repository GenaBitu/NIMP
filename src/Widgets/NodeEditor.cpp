#include "Widgets/NodeEditor.hpp"

#include "Registry.hpp"
#include "Nodes.hpp"

NodeEditor::NodeEditor() : ActionWidgetContainer{}, nodes{}, paths{}
{
    for(std::vector<Node*>::iterator it{Registry::getRegistry()->intrinsic->nodes.begin()}; it != Registry::getRegistry()->intrinsic->nodes.end(); it++)
    {
       nodes.push_back(new NodeGraphics{this, *it});
    }
    for(std::vector<NodeGraphics*>::iterator it{nodes.begin()}; it != nodes.end(); it++)
    {
        (*it)->rebuildConnections();
    }
}

void NodeEditor::populateBar(SwitchingBar* bar, QWidget* widget)
{
    NodeEditor* editor{dynamic_cast<NodeEditor*>(widget)};
    if(editor == nullptr)
    {
        // TODO: DIE HORRIBLY IN FLAMES
        return;
    }
    QMenu* addNode{new QMenu{"Add node"}};
    QMenu* addInput{new QMenu{"File input"}};
    QAction* addBMP{new QAction{"BMP file", editor}};
    QObject::connect(addBMP, &QAction::triggered, [editor]()->void{editor->addNode(new BMPinput{"tex2D2.bmp"});});
    addInput->addAction(addBMP);
    addNode->addMenu(addInput);
    bar->addMenu(addNode);
}

void NodeEditor::addNode(Node* node)
{
    NodeGraphics* nodeGraphic{new NodeGraphics{this, node}};
    nodes.push_back(nodeGraphic);
    nodeGraphic->rebuildConnections();
}

void NodeEditor::mousePressEvent(QMouseEvent* event)
{
    new NodePathCutter{this, event->pos()};
}
