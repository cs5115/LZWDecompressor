#include "CodeTranslator.h"

CodeTranslator::CodeTranslator() {
	this->read_number = ODD;
}

int CodeTranslator::readCode(std::ifstream &fin) {
	// Each code comprises 12bits: a full_byte and a shared_byte
	int shared_byte, full_byte;
	int code = 0;

	if (read_number == ODD) {	
		full_byte = fin.get();
		if (fin.eof()) return -1;
		shared_byte = fin.get();
		if (fin.eof()) { 
			std::cout << "Incomplete trailing code" << std::endl; 
			return -1; 
		}

		// shared_byte is stored for manipulation in next readCode() execution
		this->stored_byte = shared_byte;

		// ODD codes comprise full_byte and the upper 4 bits of shared_byte
		code += (full_byte << 4) + (shared_byte >> 4); 

		// Handle the case where there are an ODD total number of 12bit codes
		if (fin.peek() == EOF) { 
			code = (full_byte << 8) + shared_byte; 
		}

		// The next read will be EVEN
		read_number = EVEN; 
	} 
	else {
		full_byte = fin.get();
		if (fin.eof()) return -1;

		// Retrieve the shared_byte stored from previous readCode() execution
		shared_byte = this->stored_byte;

		// EVEN codes comprises full_byte and the lower 4 bits of shared_byte
		code += ((shared_byte & 0xF) << 8) + full_byte;

		// The next read will be ODD
		read_number = ODD; 
	}
	return code;
}