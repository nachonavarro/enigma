#include "Reflector.h"

// Not configurable. Uses the following function 
// to map letters.
int Reflector::inputOutput(int n) {
	return (n + 13) % lettersInAlphabet;
}
