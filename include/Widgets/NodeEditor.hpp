#pragma once

#include "Global.hpp"

class Node;
class NodeInput;
class NodeOutput;

class NodeEditor : public QWidget
{
    #include "Widgets/NodeEditor/NodeConnectorLeft.hpp"
    #include "Widgets/NodeEditor/NodeConnectorRight.hpp"
    #include "Widgets/NodeEditor/NodeContainer.hpp"
public:
    NodeEditor();
protected:
};
