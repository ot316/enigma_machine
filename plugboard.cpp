#include"plugboard.hpp"
#include<string>
#include<iostream>
using namespace std;

Plugboard::Plugboard(string mappings) {
	check_config(mappings);
	cout << "Plugboard initialised with " << mappings << endl;
}

void Plugboard::check_config(string mappings) {
	for (auto i = 0u; i < mappings.size(); i++) {
		for (auto j = i + 1; j < mappings.size(); j++) {
			if (mappings[i] == mappings[j]) {
				cerr << "Plugboard mapping is invalid\n";
				exit(IMPOSSIBLE_PLUGBOARD_CONFIGURATION);
			}
		}
	}
	if (mappings.size() % 2 == 1) {
		cerr << "Plugboard mapping is incomplete";
		exit(INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS);
	}
}
