#pragma once

#include "Global.hpp"

class Node;
class NodeInput;
class NodeOutput;

class NodeEditor : public QWidget
{
    #include "Widgets/NodeEditor/NodeConnectorLeft.hpp"
    #include "Widgets/NodeEditor/NodeConnectorRight.hpp"
    #include "Widgets/NodeEditor/NodeGraphics.hpp"
    #include "Widgets/NodeEditor/NodePath.hpp"
public:
    NodeEditor();
protected:
    std::vector<NodeGraphics*> nodes;
    std::vector<NodePath*> paths;
};
