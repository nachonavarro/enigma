#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include "InputOutputMap.h"
#include <vector>

using namespace std;

class Plugboard : public InputOutputMap {
public:
	Plugboard(char* file);
	int inputOutput(int n);	
private:
	vector<int> pairs;
};

#endif
