#include "Widgets/NodeEditor.hpp"

#include "Nodes/CanvasNode.hpp"
#include "Registry.hpp"

NodeEditor::NodeEditor() {
    for(std::vector<Node*>::iterator it{Registry::getRegistry()->intrinsic->nodes.begin()}; it != Registry::getRegistry()->intrinsic->nodes.end(); it++)
    {
       new NodeGraphics{this, *it};
    }
}
