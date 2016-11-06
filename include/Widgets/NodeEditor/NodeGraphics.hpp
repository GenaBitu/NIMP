#pragma once

#include "Global.hpp"

#include "WidgetActions/Draggable.hpp"

class Node;
class NodeEditor;
class NodeInputGraphics;
class NodeOutputGraphics;
class NodeInterfaceGraphics;

class NodeGraphics : public Draggable
{
    Q_OBJECT
    Q_DISABLE_COPY(NodeGraphics)
public:
    std::vector<NodeInputGraphics*> inputs;
    std::vector<NodeOutputGraphics*> outputs;
    std::vector<NodeInterfaceGraphics*> interfaces;
    NodeGraphics(NodeEditor* parent, Node* node);
    void addInterfaces();
    void addConnections();
    void rebuildInterfaces();
    void rebuildConnections();
    static void connect(NodeOutputGraphics* left, NodeInputGraphics* right);
    ~NodeGraphics();
protected slots:
    void reposition();
    void destruct();
protected:
    Node* node;
    static const int headerHeight;
    static const int footerHeight;
    int interfaceHeight;
    int connectionHeight;
    virtual void keyPressEvent(QKeyEvent* event);
    virtual void moveEvent(QMoveEvent*);
    virtual void mouseReleaseEvent(QMouseEvent* event);
    virtual void paintEvent(QPaintEvent*);
    void reMask();
    void removeInterfaces();
    void removeConnections();
    void updateConnections();
    void deleteNode();
};
