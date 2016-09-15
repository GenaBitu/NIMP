#include "Widgets/NodeEditor.hpp"

#include "Nodes/CanvasNode.hpp"
#include "Registry.hpp"

NodeEditor::NodeEditor() {
    for(std::vector<Node*>::iterator it{Registry::getRegistry()->intrinsic->nodes.begin()}; it != Registry::getRegistry()->intrinsic->nodes.end(); it++)
    {
       nodes.push_back(new NodeGraphics{this, *it});
    }
    /*for(std::vector<NodeGraphics*>::iterator it{nodes.begin()}; it != nodes.end(); it++)
    {
        (*it)->buildPaths();
    }*/
}
