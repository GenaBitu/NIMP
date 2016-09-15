#include "NodeSystem/NodeIO.hpp"

NodeIO::NodeIO(Node* parent, std::string name) : name{name}, parent{parent} {}

NodeIO::~NodeIO() {}
