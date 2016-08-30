#include "Widgets/NodeEditor.hpp"

#include "Nodes/CanvasNode.hpp"

NodeEditor::NodeEditor() {
    NodeContainer* nd1{new NodeContainer(this, CNVS)};
}
