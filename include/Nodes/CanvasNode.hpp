#pragma once

#include "../Global.hpp"

#include "include/NodeSystem/Node.hpp"

class Texture;

class CanvasNode : public Node
{
public:
    CanvasNode();
    Texture* getTexture();
};
