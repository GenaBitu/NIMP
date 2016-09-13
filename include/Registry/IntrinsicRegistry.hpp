#pragma once

#include "Global.hpp"

class IntrinsicRegistry
{
public:
    std::vector<Node*> nodes;
    std::vector<NodeEditor::NodeGraphics*> nodeGraphics;
    IntrinsicRegistry();
};
