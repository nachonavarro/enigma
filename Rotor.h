#ifndef ROTOR_H
#define ROTOR_H

#include "InputOutputMap.h"
#include <vector>

using namespace std;

class Rotor : public InputOutputMap {
public:
	Rotor(char* file);
	int inputOutput(int n);
	int inverseInputOutput(int n);
	int getRotations();
	int rotate();
	bool rotatedEntirely();

private:
	vector<int> forwardMap;
	vector<int> backwardMap;
	int rotations;
};

#endif
