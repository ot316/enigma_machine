#include"plugboard.hpp"
#include<string>
#include<iostream>
using namespace std;

int Plugboard::configure(string config) {
	// cout << "plugboard configured with " << config << endl;
	for (auto i = 0u; i < config.size(); i++) {
		for (auto j = i + 1; j < config.size(); j++) {
			if (config[i] == config[j]) {
				cerr << "Plugboard mapping is invalid\n";
				return IMPOSSIBLE_PLUGBOARD_CONFIGURATION;
			}
		}
	}
	if (config.size() % 2 == 1) {
		cerr << "Plugboard mapping is incomplete";
		return INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS;
	}
	mappings = config;
	return NO_ERROR;
}

void Plugboard::encipher(char& ch) {
	int index = mappings.find(ch);
	if (index != string::npos) {
		if (index % 2 == 0)
			ch = mappings[index + 1];
		else
			ch = mappings[index - 1];
	}
}