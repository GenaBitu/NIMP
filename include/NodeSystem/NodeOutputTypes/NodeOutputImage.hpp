#pragma once

#include "Global.hpp"

#include "NodeSystem/NodeOutput.hpp"
#include "NodeSystem/NodeDataTypes/NodeDataImage.hpp"

class NodeOutputImage : public NodeOutput
{
public:
    NodeOutputImage(Node* parent, std::string name);
    virtual NodeDataImage* getData() override;
};
