#include "Nodes/InvertMonochrome.hpp"

#include "NodeSystem/NodeInput.hpp"
#include "NodeSystem/NodeOutput.hpp"
#include "NodeSystem/NodeDataTypes/NodeDataMonochrome.hpp"
#include "RowSelector.hpp"

InvertMonochrome::InvertMonochrome()
{
	inputs.push_back(new NodeInput{this, NodeIO::DataType::MONOCHROME, "Image"});
	outputs.push_back(new NodeOutput{this, NodeIO::DataType::MONOCHROME, "Image"});
	relations.push_back(std::bind(&InvertMonochrome::invert, this, std::placeholders::_1));
}

std::string InvertMonochrome::nodeName()
{
	return "Invert Monochromatic";
}

NodeDataMonochrome* InvertMonochrome::invert(const std::vector<NodeInput*> inputs)
{
	NodeDataMonochrome* input{dynamic_cast<NodeDataMonochrome*>(inputs[0]->getData())};
	if(input == nullptr)
	{
		return nullptr;
	}
	for(int i{0}; i < input->width; i++)
	{
		for(int j{0}; j < input->height; j++)
		{
			(*input)[i][j].v = 1 - (*input)[i][j].v;
		}
	}
	return input;
}
