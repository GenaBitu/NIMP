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
    QObject::connect(Registry::getRegistry()->notifier, &RegistryNotifier::nodeAdded, this, &NodeEditor::addNode, Qt::QueuedConnection);
}

void NodeEditor::populateBar(SwitchingBar* bar, QWidget* widget)
{
    NodeEditor* editor{dynamic_cast<NodeEditor*>(widget)};
    if(editor == nullptr)
    {
        // TODO: DIE HORRIBLY IN FLAMES
        return;
    }
    QMenu* node{new QMenu{"Add node"}};
    QMenu* input{new QMenu{"Input"}};
    QMenu* output{new QMenu{"Output"}};
    QMenu* effect{new QMenu{"Effect"}};
    QAction* inputBMP{new QAction{"BMP file", editor}};
    QAction* outputCanvas{new QAction{"Canvas", editor}};
    QAction* effectGaussianBlur{new QAction{"Gaussian blur", editor}};
    QObject::connect(inputBMP, &QAction::triggered, []()->void{new BMPinput{"tex2D2.bmp"};});
    QObject::connect(outputCanvas, &QAction::triggered, []()->void{new CanvasNode{};});
    QObject::connect(effectGaussianBlur, &QAction::triggered, []()->void{new GaussianBlur{};});
    input->addAction(inputBMP);
    output->addAction(outputCanvas);
    effect->addAction(effectGaussianBlur);
    node->addMenu(input);
    node->addMenu(output);
    node->addMenu(effect);
    bar->addMenu(node);
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
