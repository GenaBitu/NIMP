#include "NodeSystem/NodeIONotifier.hpp"

void NodeIONotifier::reconnected() const
{
	emit QtReconnected();
}
