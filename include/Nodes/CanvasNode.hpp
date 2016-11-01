#pragma once

#include "Global.hpp"

#include "NodeSystem/Node.hpp"

class Texture;

class CanvasNode : public Node
{
    Q_OBJECT
    Q_DISABLE_COPY(CanvasNode)
public:
    CanvasNode(int x = 0, int y = 0);
    virtual std::string nodeName();
    Texture* getTexture();
signals:
    void reconnected();
private slots:
    void inputsReconnected();
};
