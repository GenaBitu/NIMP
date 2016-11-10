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
    virtual std::string nodeName() override;
    Texture* getTexture();
	~CanvasNode();
signals:
    void imageChanged();
private slots:
    void inputsReconnected();
	void nameChanged();
};
