#include"rotor.hpp"
#include"constants.hpp"

#include<iostream>
using namespace std;

Rotor::Rotor(){
	next = nullptr;
}

int Rotor::configure(string config, char starting_position) {

	if (config.size() < ALPHABET_LENGTH) {
		cerr << "Not enough parameters in rotor config file\n";
		return INVALID_ROTOR_MAPPING;
	}

	// Rotate to starting position and parse the config string
	rotation = ALPHABET.find(starting_position);
	mappings = config.substr(0, ALPHABET_LENGTH);
	notch_positions = config.substr(ALPHABET_LENGTH, string::npos);

	return checkMappings();
}

void Rotor::encipher(char& ch) {
	int index = ALPHABET.find(ch);
	ch = mappings[(ALPHABET_LENGTH + index - rotation) % ALPHABET_LENGTH];
	//reverseEncipher(ch);
}

void Rotor::reverseEncipher(char& ch) {
	int index = mappings.find(ch);
	ch = ALPHABET[(ALPHABET_LENGTH + index + rotation) % ALPHABET_LENGTH];
}

void Rotor::rotate() {
	rotation = (rotation + 1) % ALPHABET_LENGTH;
	auto position = ALPHABET[rotation];
	if (notch_positions.find(position) != string::npos)
		if (next)
			next->rotate();
}

int Rotor::checkMappings() {
	for (char i = 'A'; i <= 'Z'; i++) {
		if (mappings.find(i) == string::npos) {
			cerr << "The rotor config file contains an invalid mapping\n";
			return INVALID_ROTOR_MAPPING;
		}
	}
	return NO_ERROR;
}


