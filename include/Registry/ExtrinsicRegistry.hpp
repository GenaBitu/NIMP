#pragma once

#include "Global.hpp"

class GuiSettings;

class ExtrinsicRegistry
{
public:
    QMainWindow* window;
    BlendSplitter* splitter;
    GuiSettings* GUI;
    ExtrinsicRegistry();
    ExtrinsicRegistry(const ExtrinsicRegistry&) = delete;
    ExtrinsicRegistry& operator=(const ExtrinsicRegistry&) = delete;
};
