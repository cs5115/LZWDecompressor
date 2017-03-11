#include "Dictionary.h"

Dictionary::Dictionary() {
	std::string str;
	for (int i = 0; i < 256; i++) {
		str = "";
		str += i;
		this->string_vec.push_back(str);
	}
	this->string_vec_size = 256;
}

std::string Dictionary::getString(int code) {	
	if (code >= string_vec_size) return "";
	else return string_vec[code];
}

void Dictionary::addString(std::string str) {
	this->string_vec.push_back(str);
	string_vec_size++;
	if (this->isFull()) this->reset();
}

bool Dictionary::isFull() {
	if (string_vec_size >= MAX_DICTIONARY_LENGTH) return true;
	else return false;
}

void Dictionary::reset() {
	this->string_vec.clear();
	std::string str;
	for (int i = 0; i < 256; i++) {
		str = "";
		str += i;
		this->string_vec.push_back(str);
	}
	this->string_vec_size = 256;
}