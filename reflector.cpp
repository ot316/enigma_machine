#include"reflector.hpp"
#include"constants.hpp"

#include<string>
#include<iostream>
using namespace std;

int Reflector::configure(string config) {
	// check the mapping for a even number of characters
	if (config.size() % 2 == 1) {
		cerr << "Incorrect (odd) number of mappings in reflector file.\n";
		return INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS;
	}
	// check the mapping for repeated characters
	for (auto i = 0u; i < config.size(); i++) {
		for (auto j = i + 1; j < config.size(); j++) {
			if (config[i] == config[j]) {
				cerr << "Reflector mapping is invalid.\n";
				return INVALID_REFLECTOR_MAPPING;
			}
		}
	}
	// check that the mapping is complete
	if (config.size() != ALPHABET_LENGTH) {
		cerr << "Insufficient number of mappings in reflector file.\n";
		return INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS;
	}
	mappings = config;
	return NO_ERROR;
}

void Reflector::encipher(char& ch) {
	auto index = mappings.find(ch);
	if (index % 2 == 0)
		ch = mappings[index + 1];
	else
		ch = mappings[index - 1];
}

