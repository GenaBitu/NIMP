#pragma once

#include "Global.hpp"

class NodeDataMonochrome;

#include "NodeSystem/Node.hpp"

class SeparateRGB : public Node
{
public:
	SeparateRGB();
	virtual std::string nodeName() override;
private:
	NodeDataMonochrome* separateR(const std::vector<NodeInput*> inputs);
	NodeDataMonochrome* separateG(const std::vector<NodeInput*> inputs);
	NodeDataMonochrome* separateB(const std::vector<NodeInput*> inputs);
};
