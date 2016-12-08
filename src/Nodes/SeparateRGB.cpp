#include "Nodes/SeparateRGB.hpp"

#include "NodeSystem/NodeInputTypes/NodeInputImage.hpp"
#include "NodeSystem/NodeOutputTypes/NodeOutputMonochrome.hpp"
#include "RowSelector.hpp"

SeparateRGB::SeparateRGB()
{
	inputs.push_back(new NodeInputImage{this, NodeIO::DataType::IMAGE, "Image"});
	outputs.push_back(new NodeOutputMonochrome{this, NodeIO::DataType::MONOCHROME, "Red"});
	outputs.push_back(new NodeOutputMonochrome{this, NodeIO::DataType::MONOCHROME, "Green"});
	outputs.push_back(new NodeOutputMonochrome{this, NodeIO::DataType::MONOCHROME, "Blue"});
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
	NodeDataImage* input{dynamic_cast<NodeDataImage*>(inputs[0]->getData())};
	if(input == nullptr)
	{
		// TODO: DIE HORRIBLY IN FLAMES
		return nullptr;
	}
	NodeDataMonochrome* output{new NodeDataMonochrome{input->width, input->height}};
	for(int i{0}; i < input->width; i++)
	{
		for(int j{0}; j < input->height; j++)
		{
			(*output)[i][j].v = (*input)[i][j].r;
			(*output)[i][j].a = (*input)[i][j].a;
		}
	}
	return output;
}

NodeDataMonochrome* SeparateRGB::separateG(const std::vector<NodeInput*> inputs)
{
	NodeDataImage* input{dynamic_cast<NodeDataImage*>(inputs[0]->getData())};
	if(input == nullptr)
	{
		// TODO: DIE HORRIBLY IN FLAMES
		return nullptr;
	}
	NodeDataMonochrome* output{new NodeDataMonochrome{input->width, input->height}};
	for(int i{0}; i < input->width; i++)
	{
		for(int j{0}; j < input->height; j++)
		{
			(*output)[i][j].v = (*input)[i][j].g;
			(*output)[i][j].a = (*input)[i][j].a;
		}
	}
	return output;
}

NodeDataMonochrome* SeparateRGB::separateB(const std::vector<NodeInput*> inputs)
{
	NodeDataImage* input{dynamic_cast<NodeDataImage*>(inputs[0]->getData())};
	if(input == nullptr)
	{
		// TODO: DIE HORRIBLY IN FLAMES
		return nullptr;
	}
	NodeDataMonochrome* output{new NodeDataMonochrome{input->width, input->height}};
	for(int i{0}; i < input->width; i++)
	{
		for(int j{0}; j < input->height; j++)
		{
			(*output)[i][j].v = (*input)[i][j].b;
			(*output)[i][j].a = (*input)[i][j].a;
		}
	}
	return output;
}
