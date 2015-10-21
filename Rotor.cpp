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
		forwardMap.reserve(lettersInAlphabet);
		backwardMap.reserve(lettersInAlphabet);

		while (input >> n) {
			forwardMap[index] = n;
			backwardMap[n] = index;
			index++;
		}

		input.close();	

	} else {
		cerr << "File not opened" << endl;
	}
}

int Rotor::inputOutput(int n) {
	//Take into account the shift.
	n = (n + rotations) % lettersInAlphabet;
	//Now map the value to the respective output.
	n = forwardMap[n]; 
	//Now take into account the shift again by subtracting the rotations
	//and return the value. Note I add 26 so that mod function doesn't
	//output unwanted negative values.
	return (n - rotations + lettersInAlphabet) % lettersInAlphabet;
}

int Rotor::inverseInputOutput(int n) {
	//Take into account the shift.
	n = (n + rotations) % lettersInAlphabet;
	//Now map the value to the respective output.
	n = backwardMap[n]; 
	//Now take into account the shift again by subtracting the rotations
	//and return the value. Note I add 26 so that mod function doesn't
	//output unwanted negative values.
	return (n - rotations + lettersInAlphabet) % lettersInAlphabet;
}

int Rotor::getRotations() {
	return rotations;
}

bool Rotor:: rotatedEntirely() {
	return rotations == 26;
}

int Rotor::rotate() {	
	rotations = (rotations + 1) % lettersInAlphabet;
	return rotations;
}
