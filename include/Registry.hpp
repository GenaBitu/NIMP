#pragma once

#include "Global.hpp"

class Registry
{
    #include "Registry/ExtrinsicSettings.hpp"
    #include "Registry/GuiSettings.hpp"
public:
    ExtrinsicSettings* extrinsic;
    static Registry* getRegistry();
private:
    static Registry* instance;
    Registry();
};
