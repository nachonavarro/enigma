#ifndef REFLECTOR_H
#define REFLECTOR_H

#include "InputOutputMap.h"

class Reflector : public InputOutputMap {
public:
	Reflector();
	~Reflector();
	int inputOutput(int n);
};

#endif
