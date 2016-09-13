#pragma once

#include "Global.hpp"

#include "Widgets/NodeEditor.hpp"

class Node;

class Registry
{
    #include "Registry/ExtrinsicRegistry.hpp"
    #include "Registry/GuiSettings.hpp"
    #include "Registry/IntrinsicRegistry.hpp"
public:
    ExtrinsicRegistry* extrinsic;
    IntrinsicRegistry* intrinsic;
    static Registry* getRegistry();
private:
    static Registry* instance;
    Registry();
};
