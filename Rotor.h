#ifndef ROTOR_H
#define ROTOR_H
#include "InputOutputMap.h"
#include <vector>

using namespace std;

class Rotor : public InputOutputMap {
public:
	Rotor(char* file);
	~Rotor();
	Rotor();
	int inputOutput(int n);
	int inverseInputOutput(int n);
	void rotate();
	int getRotations();
	void resetRotations();
	bool hasRotatedEntirely();

	private:
	static const int lettersInAlphabet = 26;
	vector<int> forwardMap;
	vector<int> backwardMap;
	int rotations;
};
#endif
