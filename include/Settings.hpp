#pragma once

#include "Global.hpp"

class Settings
{
    #include "Settings/ExtrinsicSettings.hpp"
    #include "Settings/GuiSettings.hpp"
public:
    ExtrinsicSettings* extrinsic;
    static Settings* getSettings();
private:
    static Settings* instance;
    Settings();
};
