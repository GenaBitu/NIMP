#include "Widgets/NodeEditor.hpp"

#include "Nodes/CanvasNode.hpp"
#include "Registry.hpp"

NodeEditor::NodeEditor() {
    NodeGraphics* nd1{new NodeGraphics{this, Registry::getRegistry()->intrinsic->nodes[0]}};
    NodeGraphics* nd2{new NodeGraphics{this, Registry::getRegistry()->intrinsic->nodes[1]}};
}
