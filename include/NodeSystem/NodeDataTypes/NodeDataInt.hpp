#pragma once

#include "Global.hpp"

#include "NodeSystem/NodeData.hpp"

class NodeDataInt : public NodeData
{
public:
    int data;
    NodeDataInt() = delete;
    NodeDataInt(int data);
};
