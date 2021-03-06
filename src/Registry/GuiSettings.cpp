#include "Registry.hpp"

Registry::GuiSettings::GuiSettings() : palette{}, dimensions{}, keys{}, stylesheets{}
{
    palette["NodeBorder"] = Qt::black;
    palette["NodeBorderActive"] = Qt::yellow;
    palette["NodeBackground"] = Qt::lightGray;
    palette["NodeHeaderSeparator"] = Qt::darkGray;
    palette["NodeHeaderText"] = Qt::black;
    palette["NodeConnectorBorder"] = Qt::darkGray;
    palette["NodeConnectorInt"] = Qt::gray;
    palette["NodeConnectorMonochrome"] = Qt::yellow;
    palette["NodeConnectorImage"] = QColor{0xff, 0xa0, 0x00};
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
    dimensions["NodePathSharpness"] = 30;
    dimensions["NodePathCutterWidth"] = 1;
    keys["Delete"] = Qt::Key_Delete;
    stylesheets["NodeInterfaceBoolGraphics"] = "QCheckBox {background-color: " + palette["NodeBackground"].name().toStdString() + "; outline: 0;}";
	stylesheets["NodeInterfaceStringGraphics"] = "";
}
