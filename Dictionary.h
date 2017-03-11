#include <iostream>
#include <vector>
#include <string>

#define MAX_DICTIONARY_LENGTH 4096

class Dictionary {
private:
	// A vector holds the strings indexed by the 12bit compression codes
	std::vector<std::string> string_vec;
	int string_vec_size;

public:
	// Constructor initialises string_vec with the 256 ASCII characters
	Dictionary();

	// Returns the string corresponding to the code taken as input
	// If no string exists for code, an empty string is returned
	std::string getString(int code);

	// addString() adds str to string_vec at position map_index
	// If string_map isFull() it is automatically reset() to its original state
	void addString(std::string str);
	bool isFull();
	void reset();
};
