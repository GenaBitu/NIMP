#include "Settings.hpp"

Settings* Settings::instance{};

Settings::Settings() : extrinsic{new ExtrinsicSettings{}}
{
}

Settings* Settings::getSettings()
{
    if(instance == nullptr)
    {
        instance = new Settings;
    }
    return instance;
}
