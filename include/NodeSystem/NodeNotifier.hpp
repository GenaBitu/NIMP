#pragma once

#include "Global.hpp"

class NodeNotifier : public QObject
{
    Q_OBJECT
public:
    void moved() const;
    void deleted() const;
    void imageChanged() const;
signals:
    void QtMoved() const;
    void QtDeleted() const;
    void QtImageChanged() const;
};
