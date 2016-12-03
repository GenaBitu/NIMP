#include "NodeSystem/NodeNotifier.hpp"

void NodeNotifier::moved() const
{
    emit QtMoved();
}

void NodeNotifier::deleted() const
{
    emit QtDeleted();
}

void NodeNotifier::imageChanged() const
{
    emit QtImageChanged();
}
