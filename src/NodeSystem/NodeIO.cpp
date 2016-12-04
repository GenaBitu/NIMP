#include "NodeSystem/NodeIO.hpp"

#include "NodeSystem/NodeIONotifier.hpp"

NodeIO::NodeIO(Node* parent, std::string name) : name{name}, notifier{new NodeIONotifier{}}, parent{parent} {}

NodeIO::~NodeIO() {}
