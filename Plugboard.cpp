#include "Plugboard.h"
#include <fstream>
#include <vector>
#include <iostream>

Plugboard::Plugboard(char* file) {
	
	std::ifstream input;
	input.open(file);	
	
	if (input.is_open()) {
		int n;
		input >> std::ws;
		while (input >> n) {	
			pairs.push_back(n);
		}
		input.close();	
	} else {
		std::cerr << "File not open" << std::endl;
	}
}

Plugboard::~Plugboard() {}

int Plugboard::inputOutput(int n) {

	int evenOrOddIndex;

	for (int i = 0; i < pairs.size(); i++) {
		
		// If we find the number in the array, the only thing left to do is to 
		// know if we pair it with the next number or the previous number in
		// the array. If the index is even, we pair it up with the next
		// number, and if it's odd, with the previous number. Note that 
		// the array access is always legal as we are assured there's an even 
		// number of numbers, therefore an odd number of indexes. 
		if (pairs[i] == n &&  i % 2 == 0) {
			return pairs[i + 1];
		} else if (pairs[i] == n && i % 2 == 1) {
			return pairs[i - 1];
		}
	}
	return n;
}
