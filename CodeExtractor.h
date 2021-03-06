#include <fstream>
#include <iostream>

#define ODD 1
#define EVEN 2

class CodeExtractor {
private: 
	int stored_byte;
	// Stores the byte shared by two adjacent codes
	
	int read_number;
	// Determines how to manipulate bits to create a 12bit code
	
public:
	CodeExtractor();
	// Constructor assigns ODD (defined above) as initial value of read_number

	int getCode(std::ifstream& fin);
	// Takes an ifstream and reads bytes from it. These bytes are
	// converted to an integer corresponding to a 12bit compression code. If no 
	// code can be extracted, -1 is returned. The value of read_number is 
	// changed from ODD to EVEN and vice versa on each execution.
};
