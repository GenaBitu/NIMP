#pragma once

#include "Global.hpp"

class Node;
class NodeInput;
class NodeOutput;

class NodeEditor : public QWidget
{
public:
    #include "Widgets/NodeEditor/NodeConnectorLeft.hpp"
    #include "Widgets/NodeEditor/NodeConnectorRight.hpp"
    #include "Widgets/NodeEditor/NodeGraphics.hpp"
    NodeEditor();
protected:
};
