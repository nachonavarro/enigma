#include "Rotor.h"
#include <iostream>
#include <fstream>

using namespace std;

Rotor::Rotor(char* file) {
	rotations = 0;
	ifstream input;
	input.open(file);
	if (input.is_open()) {
		int n;
		int index = 0;
		input >> ws;
		forwardMap.reserve(26);
		backwardMap.reserve(26);
		while (input >> n) {
			forwardMap[index] = n;
			backwardMap[n] = index;
			index++;
		}
		input.close();	
	} else {
		std::cerr << "File not opened" << std::endl;
	}
}

Rotor::Rotor() {
}

Rotor::~Rotor(){
}

int Rotor::inputOutput(int n) {
	return (forwardMap[(n + rotations) % 26] - rotations + 26) % 26;	
}

int Rotor::inverseInputOutput(int n) {
	return (backwardMap[(n + rotations) % 26] - rotations + 26) % 26;
}

int Rotor::getRotations() {
	return rotations;
}

void Rotor::resetRotations() {
	rotations = 0;
}

bool Rotor::hasRotatedEntirely() {
	return rotations == 26;
}

void Rotor::rotate() {	
	rotations++;
}
