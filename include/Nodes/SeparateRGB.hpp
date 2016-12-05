#pragma once

#include "Global.hpp"

#include "NodeSystem/Node.hpp"
#include "NodeSystem/NodeDataTypes/NodeDataMonochrome.hpp"

class SeparateRGB : public Node
{
public:
	SeparateRGB();
	virtual std::string nodeName();
private:
	NodeDataMonochrome* separateR(const std::vector<NodeInput*> inputs);
	NodeDataMonochrome* separateG(const std::vector<NodeInput*> inputs);
	NodeDataMonochrome* separateB(const std::vector<NodeInput*> inputs);
};
