#include "Registry.hpp"

Registry::GuiSettings::GuiSettings() : palette{}, dimensions{}
{
    palette["NodeBorder"] = Qt::black;
    palette["NodeBorderActive"] = Qt::yellow;
    palette["NodeBackground"] = Qt::lightGray;
    palette["NodeHeaderSeparator"] = Qt::darkGray;
    palette["NodeHeaderText"] = Qt::black;
    palette["NodeConnectorBorder"] = Qt::darkGray;
    palette["NodeConnectorBackground"] = Qt::yellow;
    palette["NodeConnectorText"] = Qt::black;
    palette["NodePath"] = Qt::black;
    palette["NodePathActive"] = Qt::red;
    palette["NodePathCutter"] = Qt::red;
    dimensions["NodeMargin"] = 10;
    dimensions["NodeCornerRadius"] = 10;
    dimensions["NodeBorderWidth"] = 2;
    dimensions["NodeHeaderHeight"] = 30;
    dimensions["NodeHeaderSeparatorHeight"] = 2;
    dimensions["NodeConnectorDiameter"] = 20;
    dimensions["NodeConnectorBorder"] = 1;
    dimensions["NodeConnectorSpacing"] = 10;
    dimensions["NodeInterfaceSpacing"] = 10;
    dimensions["NodePathWidth"] = 1;
    dimensions["NodePathClickableWidth"] = 20;
    dimensions["NodePathSharpness"] = 75;
    dimensions["NodePathCutterWidth"] = 1;
}
