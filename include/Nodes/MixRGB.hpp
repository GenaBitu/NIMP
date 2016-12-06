#pragma once

#include "Global.hpp"

class NodeDataImage;

#include "NodeSystem/Node.hpp"

class MixRGB : public Node
{
public:
	MixRGB();
	virtual std::string nodeName() override;
private:
	NodeDataImage* mix(const std::vector<NodeInput*> inputs);
};
