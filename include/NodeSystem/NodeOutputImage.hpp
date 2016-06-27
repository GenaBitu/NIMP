#pragma once

#include "../Global.hpp"

#include "NodeDataImage.hpp"
#include "NodeOutput.hpp"

class NodeOutputImage : public NodeOutput
{
public:
    NodeOutputImage(Node* parent);
    virtual NodeDataImage* getData();
};
