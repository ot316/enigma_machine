#include"rotor.hpp"
#include"constants.hpp"

#include<iostream>
#define C(i) (i + 'A')
#define SHIFTED_C(i) ((i - rotation + ALPHABET_LENGTH) % ALPHABET_LENGTH) + 'A'
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
	for(auto i = 0u; i < ALPHABET_LENGTH; i++) {
		reverseCharsMap[ALPHABET.find(mappings[i])] = i;
	}
	notch_positions = config.substr(ALPHABET_LENGTH, string::npos);

	return checkMappings();
}


void Rotor::encipher(char& ch) {
	ch = mappings[(ch + 'A' + rotation) % ALPHABET_LENGTH] - 'A';
	ch = ((ch - rotation + ALPHABET_LENGTH) % ALPHABET_LENGTH) + 'A';
}

void Rotor::reverseEncipher(char& ch) {
	ch = reverseCharsMap[(ch + 'A' + rotation) % ALPHABET_LENGTH];
	ch = ((ch - rotation + ALPHABET_LENGTH) % ALPHABET_LENGTH) + 'A';
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


