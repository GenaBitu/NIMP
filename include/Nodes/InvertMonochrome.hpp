#pragma once

#include "Global.hpp"

class NodeDataMonochrome;

#include "NodeSystem/Node.hpp"

class InvertMonochrome : public Node
{
public:
	InvertMonochrome();
	std::string nodeName() override;
private:
	NodeDataMonochrome* invert(const std::vector<NodeInput*> inputs);
};
