#include "NodeSystem/NodeIO.hpp"

NodeIO::NodeIO(Node* parent, std::string name) : QObject{}, name{name}, parent{parent} {}

NodeIO::~NodeIO() {}
