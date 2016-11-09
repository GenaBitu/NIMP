#pragma once

#include "Global.hpp"

class GuiSettings
{
public:
    std::map<std::string, QColor> palette;
    std::map<std::string, int> dimensions;
	std::map<std::string, Qt::Key> keys;
	std::map<std::string, std::string> stylesheets;
    GuiSettings();
};
