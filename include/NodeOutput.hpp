#pragma once

#include "Global.hpp"

class NodeInput;

class NodeOutput
{
public:
    NodeOutput();
protected:
    NodeInput* connection;
};
