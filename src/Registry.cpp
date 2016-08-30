#include "Registry.hpp"

Registry* Registry::instance{};

Registry::Registry() : extrinsic{new ExtrinsicRegistry{}}
{
}

Registry* Registry::getRegistry()
{
    if(instance == nullptr)
    {
        instance = new Registry;
    }
    return instance;
}
