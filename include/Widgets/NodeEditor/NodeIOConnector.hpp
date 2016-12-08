#pragma once

#include "Global.hpp"

class NodeInputGraphics;
class NodeOutputGraphics;
class NodeIO;

class NodeIOConnector : public QWidget
{
    Q_OBJECT
public:
    NodeIOConnector(NodeInputGraphics* parent, NodeIO* connector, int x = 0, int y = 0);
    NodeIOConnector(NodeOutputGraphics* parent, NodeIO* connector, int x = 0, int y = 0);
	NodeIOConnector(const NodeIOConnector&) = default;
	NodeIOConnector& operator=(const NodeIOConnector&) = default;
protected:
    virtual void mousePressEvent(QMouseEvent*) override;
    virtual void paintEvent(QPaintEvent*) override;
private:
    void init(int x, int y);
	const NodeIO* const connector;
};
