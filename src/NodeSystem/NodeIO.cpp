#include "NodeSystem/NodeIO.hpp"

#include "NodeSystem/NodeIONotifier.hpp"

NodeIO::NodeIO(Node* parent, DataType type, std::string name) : type{type}, name{name}, notifier{new NodeIONotifier{}}, parent{parent} {}

NodeIO::~NodeIO() {}
