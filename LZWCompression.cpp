#include "LZWCompression.h"

void decompress(std::string compressed_file, std::string decompressed_file) {
	std::cout << "Decompressing, please wait..." << std::endl;

	// Open the file indicated by compressed_file for reading
	// Open the file indicated by decompressed_file for writing
	// Check for errors in opening both input and output files
	std::ifstream fin(compressed_file, std::ifstream::in | std::ios_base::binary);
	if (fin.fail()) {
		std::cout << "Input file opening failed" << std::endl;
		exit(1);
	}
	std::ofstream fout(decompressed_file, std::ofstream::out);
	if (fout.fail()) {
		std::cout << "Ouput file opening failed" << std::endl;
		exit(1);
	}

	// Create a CodeExtractor to read each 12bit code from the ifstream
	CodeExtractor *extractor = new CodeExtractor(); 

	// Create a Dictionary to map each 12-bit code to the corresponding string
	Dictionary *dictionary = new Dictionary();

	int curr_code;
	int next_code;
	std::string curr_string;
	std::string next_string;
	
	// Loop until all the 12bit codes have been read from the ifstream
	curr_code = extractor->getCode(fin);
	while (curr_code != -1) {	

		// Convert curr_code to a string and output to ofstream
		curr_string = dictionary->getString(curr_code); 
		fout << curr_string;
		
		// Read next_code and convert to string 
		next_code = extractor->getCode(fin);
		if (next_code == -1) break;
		next_string = dictionary->getString(next_code);
		
		// Update dictionary 
		if (next_string == "") {
			dictionary->addString(curr_string + curr_string[0]);
		}
		else {		
			dictionary->addString(curr_string + next_string[0]);
		}
		
		curr_code = next_code;
	}

	delete dictionary;
	delete extractor;
	dictionary = NULL;
	extractor = NULL;	
	fin.close();
	fout.close();
	std::cout << "Decompression complete." << std::endl;
}
