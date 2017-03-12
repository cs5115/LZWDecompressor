#include <iostream>
#include <vector>
#include <string>

#define MAX_DICTIONARY_LENGTH 4096

class Dictionary {
private:
	std::vector<std::string> string_vec;
	// A vector holds the strings indexed by the 12bit compression codes

	int string_vec_size;

public:
	Dictionary();
	// Constructor initialises string_vec with the 256 ASCII characters
	
	std::string getString(int code);
	// Returns the string corresponding to the code taken as input
	// If no string exists for code, an empty string is returned
		
	void addString(std::string str);
	// addString() adds str to string_vec at position map_index
	// If string_map isFull() it is automatically reset() to its original state

	bool isFull();
	void reset();
};
