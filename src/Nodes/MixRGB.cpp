#include "Nodes/MixRGB.hpp"

#include "NodeSystem/NodeInputTypes/NodeInputMonochrome.hpp"
#include "NodeSystem/NodeOutputTypes/NodeOutputImage.hpp"
#include "RowSelector.hpp"

MixRGB::MixRGB()
{
	inputs.push_back(new NodeInputMonochrome{this, "Red"});
	inputs.push_back(new NodeInputMonochrome{this, "Green"});
	inputs.push_back(new NodeInputMonochrome{this, "Blue"});
	outputs.push_back(new NodeOutputImage{this, "Image"});
	relations.push_back(std::bind(&MixRGB::mix, this, std::placeholders::_1));
}

std::string MixRGB::nodeName()
{
	return "Separate RGB";
}

NodeDataImage* MixRGB::mix(const std::vector<NodeInput*> inputs)
{
	NodeDataMonochrome* inputR{dynamic_cast<NodeDataMonochrome*>(inputs[0]->getData())};
	NodeDataMonochrome* inputG{dynamic_cast<NodeDataMonochrome*>(inputs[1]->getData())};
	NodeDataMonochrome* inputB{dynamic_cast<NodeDataMonochrome*>(inputs[2]->getData())};
	if((inputR == nullptr) or (inputR == nullptr) or (inputR == nullptr))
	{
		// TODO: DIE HORRIBLY IN FLAMES
		return nullptr;
	}
	NodeDataImage* output{new NodeDataImage{inputR->width, inputR->height}};
	for(int i{0}; i < inputR->width; i++)
	{
		for(int j{0}; j < inputR->height; j++)
		{
			(*output)[i][j].r = (*inputR)[i][j].v;
			(*output)[i][j].g = (*inputG)[i][j].v;
			(*output)[i][j].b = (*inputB)[i][j].v;
			(*output)[i][j].a = (*inputR)[i][j].a;
		}
	}
	return output;
}
