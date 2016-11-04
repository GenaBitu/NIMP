#include "include/Registry.hpp"

Registry::ExtrinsicRegistry::ExtrinsicRegistry() : window{}, splitter{}, GUI{new GuiSettings{}}, keys{}
{
    keys["Delete"] = Qt::Key_Delete;
}
