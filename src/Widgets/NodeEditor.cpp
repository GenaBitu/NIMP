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
        (*it)->addInterfaces();
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
    QMenu* addInput{new QMenu{"Input"}};
    QMenu* addOutput{new QMenu{"Output"}};
    QAction* addBMP{new QAction{"BMP file", editor}};
    QAction* addCanvas{new QAction{"Canvas", editor}};
    QObject::connect(addBMP, &QAction::triggered, [editor]()->void{editor->addNode(new BMPinput{"tex2D2.bmp"});});
    QObject::connect(addCanvas, &QAction::triggered, [editor]()->void{editor->addNode(new CanvasNode{});});
    addInput->addAction(addBMP);
    addOutput->addAction(addCanvas);
    addNode->addMenu(addInput);
    addNode->addMenu(addOutput);
    bar->addMenu(addNode);
}

void NodeEditor::addNode(Node* node)
{
    NodeGraphics* nodeGraphic{new NodeGraphics{this, node}};
    nodes.push_back(nodeGraphic);
    nodeGraphic->addInterfaces();
}

void NodeEditor::mousePressEvent(QMouseEvent* event)
{
    new NodePathCutter{this, event->pos()};
}
