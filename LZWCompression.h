#include <iostream>
#include <string>
#include "Dictionary.h"
#include "CodeTranslator.h"

// This function will read from a compressed file and create a new file to hold
// the decompressed contents. It is written for files compressed with the LZW 
// algorithm using fixed width 12bit codes.
//
// If no filepath is included in the name it is assumed that it is in the current
// working directory.
void decompress(std::string compressed_file, std::string decompressed_file);


