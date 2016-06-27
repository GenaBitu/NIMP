#pragma once

#include "../Global.hpp"

#include "NodeDataImage.hpp"
#include "NodeInput.hpp"

class NodeInputImage : public NodeInput
{
public:
    NodeInputImage(Node* parent);
    virtual NodeDataImage* getData();
};
