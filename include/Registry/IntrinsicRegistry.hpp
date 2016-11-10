#pragma once

#include "Global.hpp"

class IntrinsicRegistry
{
public:
    std::vector<Node*> nodes;
	std::map<CanvasNode*, std::string> canvases;
    IntrinsicRegistry();
};
