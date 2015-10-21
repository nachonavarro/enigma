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
void rotateRotors(int);

vector<Rotor*> rotors;
int numOfRotors;
Plugboard* plugboard;
Reflector* reflector;


int main(int argc, char **argv) {
  
	if (argc < 2) {
		throw invalid_argument("wrong number of inputs");
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
	cin >> ws;

	while (cin >> current) {
		try {
			cout << enigma(current);
		} catch (invalid_argument& e) {
			cerr << "Please input only capital letters" << endl;
		}
	}
	
	return 0;
}

char enigma(char c) {

	if (!isalpha(c) || !isupper(c)) {
		throw invalid_argument("Capital letters only");
	}

	// Since we are working with numbers, convert char (A,B,C..) to (0,1,2...)
	int n = c - 'A';

	//The number passes through the plugboard first.
	n = plugboard->inputOutput(n);

	//Then through the rotors.
	for (vector<Rotor*>::iterator it = rotors.begin(); 
			it != rotors.end(); ++it) {
		n = (*it)->inputOutput(n);
	}

	//Then through the reflector.
	n = reflector->inputOutput(n);
	
	for (vector<Rotor*>::reverse_iterator it = rotors.rbegin(); 
			it != rotors.rend(); ++it) {
		n = (*it)->inverseInputOutput(n);
	}

	//Then through the plugboard again.
	n = plugboard->inputOutput(n);

	//Before returning, rotate rotors for next call.
	//Note if there are 0 rotors the rotateRotors(0) does nothing as
	//expected.
	rotateRotors(0);
	
	//Convert int to char and return.
	return (n % 26) + 'A';

}

//Recursively rotate the rotors. If the the i'th rotor rotates and
//the rotations become 0, then you rotate the i'th + 1 rotor and so on.
void rotateRotors(int rotorNumber) {
	if (rotorNumber < rotors.size() && rotors[rotorNumber]->rotate() == 0) {
		rotateRotors(rotorNumber + 1);
	}
}
