#pragma once

#include "../../Global.hpp"

class Node;

class NodeContainer : public QWidget
{
    Q_OBJECT
public:
    NodeContainer(Node* node);
    static float padding;
    static float cornerRadius;
    static float borderWidth;
    static float headerHeight;
protected:
    Node* node;
    virtual void paintEvent(QPaintEvent*);
};
