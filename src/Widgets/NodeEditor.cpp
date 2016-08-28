#include "include/Widgets/NodeEditor.hpp"

#include "include/Widgets/NodeEditor/NodeContainer.hpp"
#include "include/Nodes/CanvasNode.hpp"

NodeEditor::NodeEditor() {
    NodeContainer* nd1{new NodeContainer(CNVS)};
    nd1->setParent(this);
}
