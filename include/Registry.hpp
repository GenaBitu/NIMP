#pragma once

#include "Global.hpp"

#include "Registry/RegistryNotifier.hpp"

class Node;
class CanvasNode;

class Registry
{
    #include "Registry/ExtrinsicRegistry.hpp"
    #include "Registry/GuiSettings.hpp"
    #include "Registry/IntrinsicRegistry.hpp"
public:
    ExtrinsicRegistry* extrinsic;
    IntrinsicRegistry* intrinsic;
    RegistryNotifier* notifier;
    static Registry* getRegistry();
private:
    static Registry* instance;
    Registry();
};
