#pragma once

#include "Global.hpp"

#include "NodeSystem/Node.hpp"

class Texture;

class CanvasNode : public Node
{
public:
    CanvasNode(int x = 0, int y = 0);
    virtual std::string nodeName();
    Texture* getTexture();
};
