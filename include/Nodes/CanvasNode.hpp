#pragma once

#include "Global.hpp"

#include "NodeSystem/Node.hpp"

class Texture;

class CanvasNode : public Node
{
public:
    CanvasNode();
    virtual std::string nodeName();
    Texture* getTexture();
};
