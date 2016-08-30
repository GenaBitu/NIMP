#pragma once

#include "Global.hpp"

class Node;
class NodeInput;

class NodeEditor : public QWidget
{
    #include "Widgets/NodeEditor/NodeConnectorLeft.hpp"
    #include "Widgets/NodeEditor/NodeContainer.hpp"
public:
    NodeEditor();
protected:
};
