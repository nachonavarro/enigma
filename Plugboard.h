#ifndef PLUGBOARD_H
#define PLUGBOARD_H
#include "InputOutputMap.h"
#include <vector>

class Plugboard : public InputOutputMap {
public:
	Plugboard(char* file);
	~Plugboard();
	int inputOutput(int n);	
private:
	std::vector<int> pairs;
};
#endif
