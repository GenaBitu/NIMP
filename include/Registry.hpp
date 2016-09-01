#pragma once

#include "Global.hpp"

class Registry
{
    #include "Registry/ExtrinsicRegistry.hpp"
    #include "Registry/GuiSettings.hpp"
    #include "Registry/IntrinsicRegistry.hpp"
public:
    ExtrinsicRegistry* extrinsic;
    static Registry* getRegistry();
private:
    static Registry* instance;
    Registry();
};
