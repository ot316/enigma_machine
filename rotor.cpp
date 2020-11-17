#include"rotor.hpp"
#include<string>
#include<iostream>
#include<algorithm>

int Rotor::configure(string config, char starting_position) {
	rotation = alphabet.find(starting_position);
	mappings = config.substr(0, ALPHABET_LENGTH);
	notch_positions = config.substr(ALPHABET_LENGTH, string::npos);
	// cout << "Rotor is initialised with " << mappings << " and notch positions " << notch_positions << ". Initial position is " << starting_position << endl;
	for (char i = 'A'; i <= 'Z'; i++) {
		if (mappings.find(i) == string::npos) {
			cerr << "The rotor config file contains an invalid mapping\n";
			return INVALID_ROTOR_MAPPING;
		}
	}
	
	return NO_ERROR;
}

void Rotor::encipher(char& ch) {
	int index = alphabet.find(ch);
	ch = mappings[(index + rotation) % ALPHABET_LENGTH];
}

void Rotor::reverse_encipher(char& ch) {
	int index = mappings.find(ch);
	ch = alphabet[(ALPHABET_LENGTH + index - rotation) % ALPHABET_LENGTH];
}

void Rotor::rotate() {
	rotation = (rotation + 1) % ALPHABET_LENGTH;
	if (notch_positions.find(ALPHABET[rotation]) != string::npos) {
		// cout << "rotation is " << rotation << " rotation notches are " << notch_positions << " rotating next" << endl;
		if (next)
			next->rotate();
	}
}


