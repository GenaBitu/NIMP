#pragma once

#include "Global.hpp"

class NodeGraphics;
class NodeInterface;

class NodeInterfaceGraphics : public QWidget
{
    Q_OBJECT
public:
    NodeInterfaceGraphics(NodeGraphics* parent, NodeInterface* interface, int y);
private:
    bool eventFilter(QObject*, QEvent* event);
};
