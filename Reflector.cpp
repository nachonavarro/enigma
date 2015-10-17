#include "Reflector.h"

Reflector::Reflector() {
}
Reflector::~Reflector() {
}

int Reflector::inputOutput(int n) {
	return (n + 13) % 26;
}
