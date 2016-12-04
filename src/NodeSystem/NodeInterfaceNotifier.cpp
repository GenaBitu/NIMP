#include "NodeSystem/NodeInterfaceNotifier.hpp"

void NodeInterfaceNotifier::valueChanged() const
{
	emit QtValueChanged();
}
