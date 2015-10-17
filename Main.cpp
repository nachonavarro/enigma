#include <stdexcept>
#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>

#include "Rotor.h"
#include "Plugboard.h"
#include "Reflector.h"

using namespace std;

char enigma(char);
void rotateRotors();

vector<Rotor*> rotors;
int numOfRotors;
Plugboard* plugboard;
Reflector* reflector;


int main(int argc, char **argv) {
  
	if (argc < 2) {
		cerr << "Wrong input. Please try again" << endl;
		return 1;
	}

	// Get rotors.
	// arg - 2 since we don't count the last argument (plugboard), 
	// and program name (./enigma).
	numOfRotors = argc - 2;
	for (int i = 1; i <= numOfRotors; i++) {
		Rotor* rotor = new Rotor(argv[i]);
		rotors.push_back(rotor);
	}
	
	// Get plugboard.	
	plugboard = new Plugboard(argv[argc - 1]);
	// Get reflector.
	reflector = new Reflector();
	
	char current;
	while (cin >> current) {
		
		if (!isupper(current)) {
			cout << " ";	
		}
		cout << enigma(current);
	}
	
	return 0;
}

char enigma(char c) {

	// Since we are working with numbers, convert char (A,B,C..) to (0,1,2...)
	int n = c - 'A';

	//The number passes through the plugboard first.
	n = plugboard->inputOutput(n);

	//Then through the rotors.
	for (int i = 0; i < numOfRotors; i++) {
		n = rotors[i]->inputOutput(n);
	}

	//Then through the reflector.
	n = reflector->inputOutput(n);
	
	for (vector<Rotor*>::reverse_iterator it = rotors.rbegin(); it != rotors.rend(); ++it) {
		n = (*it)->inverseInputOutput(n);
	}

	//Then through the plugboard again.
	n = plugboard->inputOutput(n);

	//Before returning, rotate rotors for next call.
	if (numOfRotors > 0) {
		rotateRotors();
	}
	
	//Convert int to char and return.
	return (n % 26) + 'A';

}

void rotateRotors() {
	//First one always rotates.
	rotors[0]->rotate();

	for (int i = 0; i < numOfRotors - 1; i++) {
		if (rotors[i]->hasRotatedEntirely()) {
			rotors[i]->resetRotations();
			rotors[i+1]->rotate();
		}	
	}
}

