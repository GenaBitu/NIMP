#include "Widgets/NodeEditor.hpp"

#include "Nodes/CanvasNode.hpp"
#include "Registry.hpp"

NodeEditor::NodeEditor() {
    NodeContainer* nd1{new NodeContainer(this, Registry::getRegistry()->intrinsic->nodes[0])};
}
