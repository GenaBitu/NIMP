#include "Nodes/SeparateRGB.hpp"

#include "NodeSystem/NodeInputTypes/NodeInputImage.hpp"
#include "NodeSystem/NodeOutputTypes/NodeOutputMonochrome.hpp"

SeparateRGB::SeparateRGB()
{
	inputs.push_back(new NodeInputImage{this, "Image"});
	outputs.push_back(new NodeOutputMonochrome{this, "Red"});
	outputs.push_back(new NodeOutputMonochrome{this, "Green"});
	outputs.push_back(new NodeOutputMonochrome{this, "Blue"});
	relations.push_back(std::bind(&SeparateRGB::separateR, this, std::placeholders::_1));
	relations.push_back(std::bind(&SeparateRGB::separateG, this, std::placeholders::_1));
	relations.push_back(std::bind(&SeparateRGB::separateB, this, std::placeholders::_1));
}

std::string SeparateRGB::nodeName()
{
	return "Separate RGB";
}

NodeDataMonochrome* SeparateRGB::separateR(const std::vector<NodeInput*> inputs)
{

}

NodeDataMonochrome* SeparateRGB::separateG(const std::vector<NodeInput*> inputs)
{

}

NodeDataMonochrome* SeparateRGB::separateB(const std::vector<NodeInput*> inputs)
{

}
