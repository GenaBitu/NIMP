#pragma once

#include "Global.hpp"

class Settings
{
    #include "Settings/ExtrinsicSettings.hpp"
public:
    ExtrinsicSettings* extrinsic;
    static Settings* getSettings();
private:
    static Settings* instance;
    Settings();
};
