#pragma once

#include "../Global.hpp"

#include "NodeDataImage.hpp"
#include "NodeInput.hpp"

class NodeInputImage : public NodeInput
{
public:
    NodeInputImage(Node* parent, std::string name);
    virtual NodeDataImage* getData();
};
