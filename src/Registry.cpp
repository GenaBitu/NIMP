#include "Registry.hpp"

Registry* Registry::instance{};

Registry::Registry() : extrinsic{new ExtrinsicSettings{}}
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
