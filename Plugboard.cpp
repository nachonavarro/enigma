#include "Plugboard.h"
#include <fstream>

#include <vector>
#include <iostream>

using namespace std;

Plugboard::Plugboard(char* file) {
	
	ifstream input;
	input.open(file);	
	
	if (input.is_open()) {
		
		int n;
		input >> ws; //Don't count whitespaces.

		while (input >> n) {	
			pairs.push_back(n);
		}

		input.close();

	} else {
		cerr << "File not open" << endl;
	}
}

int Plugboard::inputOutput(int n) {

	for (int index = 0; index < pairs.size(); index++) {
		
		/* If we find the number in the array, the only thing left to do is to 
		know if we pair it with the next number or the previous number in
		the array. If the index is even, we pair it up with the next
		number, and if it's odd, with the previous number. Note that 
		the array access is always legal as we are assured there's an even 
		number of numbers, therefore an odd number of indexes. 
		*/
		if (pairs[index] == n &&  index % 2 == 0) {
			return pairs[index + 1];
		} else if (pairs[index] == n && index % 2 == 1) {
			return pairs[index - 1];
		}
	}
	return n;
}
