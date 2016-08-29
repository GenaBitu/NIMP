#pragma once

#include "../../Global.hpp"

class NodeConnectorLeft : public QWidget
{
    Q_OBJECT
public:
    NodeConnectorLeft(QWidget* parent, int y);
protected:
    virtual void paintEvent(QPaintEvent*);
};
