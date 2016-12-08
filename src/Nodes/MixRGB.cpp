#include "Nodes/MixRGB.hpp"

#include "NodeSystem/NodeInput.hpp"
#include "NodeSystem/NodeOutput.hpp"
#include "NodeSystem/NodeDataTypes/NodeDataMonochrome.hpp"
#include "NodeSystem/NodeDataTypes/NodeDataImage.hpp"
#include "RowSelector.hpp"

MixRGB::MixRGB()
{
	inputs.push_back(new NodeInput{this, NodeIO::DataType::MONOCHROME, "Red"});
	inputs.push_back(new NodeInput{this, NodeIO::DataType::MONOCHROME, "Green"});
	inputs.push_back(new NodeInput{this, NodeIO::DataType::MONOCHROME, "Blue"});
	outputs.push_back(new NodeOutput{this, NodeIO::DataType::IMAGE, "Image"});
	relations.push_back(std::bind(&MixRGB::mix, this, std::placeholders::_1));
}

std::string MixRGB::nodeName()
{
	return "Mix RGB";
}

NodeDataImage* MixRGB::mix(const std::vector<NodeInput*> inputs)
{
	NodeDataMonochrome* inputR{dynamic_cast<NodeDataMonochrome*>(inputs[0]->getData())};
	NodeDataMonochrome* inputG{dynamic_cast<NodeDataMonochrome*>(inputs[1]->getData())};
	NodeDataMonochrome* inputB{dynamic_cast<NodeDataMonochrome*>(inputs[2]->getData())};
	if((inputR == nullptr) or (inputG == nullptr) or (inputB == nullptr))
	{
		return nullptr;
	}
	if((inputR->width != inputB->width) or (inputR->width != inputG->width) or (inputR->height != inputB->height) or (inputR->height != inputG->height))
	{
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
			(*output)[i][j].a = ((*inputR)[i][j].a + (*inputG)[i][j].a + (*inputB)[i][j].a) / 3;
		}
	}
	return output;
}
