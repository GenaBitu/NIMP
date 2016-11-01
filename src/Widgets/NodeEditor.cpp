#include "Widgets/NodeEditor.hpp"

#include "Registry.hpp"

NodeEditor::NodeEditor() : ActionWidgetContainer{}, nodes{}
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
