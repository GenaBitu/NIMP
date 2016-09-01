#include "Registry.hpp"

Registry* Registry::instance{};

Registry::Registry() : extrinsic{new ExtrinsicRegistry{}}, intrinsic{new IntrinsicRegistry{}}
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
