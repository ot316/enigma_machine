#include"rotor.hpp"
#include"constants.hpp"

#include<iostream>
#define C(i) (i + 'A')
#define O(ch) (ch - 'A')
#define SHIFTED_O(ch) ((O(ch) + rotation) % ALPHABET_LENGTH)
#define SHIFTED_C(i) C((i - rotation + ALPHABET_LENGTH) % ALPHABET_LENGTH)
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
	rotation = 0; //ALPHABET.find(starting_position);
	mappings = config.substr(0, ALPHABET_LENGTH);
	for( int i = 0; i < ALPHABET_LENGTH; i++) {
		charsMap[i] = ALPHABET.find(mappings[i]);
	}
	for( int i = 0; i < ALPHABET_LENGTH; i++) {
		reverseCharsMap[ALPHABET.find(mappings[i])] = i;
	}
	notch_positions = config.substr(ALPHABET_LENGTH, string::npos);

	return checkMappings();
}

void Rotor::encipher(char& ch) {
	ch = SHIFTED_C(charsMap[SHIFTED_O(ch)]);
	// reverseEncipher(ch);
	//int index = ALPHABET.find(ch);
	//ch = charsMap[(ALPHABET_LENGTH + index + rotation) % ALPHABET_LENGTH];
}

void Rotor::reverseEncipher(char& ch) {
	ch = SHIFTED_C(reverseCharsMap[SHIFTED_O(ch)]);

	//int index = mappings.find(ch);
	//ch = ALPHABET[(ALPHABET_LENGTH + index - rotation) % ALPHABET_LENGTH];
}


void Rotor::rotate() {
	// rotation = (rotation + 1) % ALPHABET_LENGTH;
	// auto position = ALPHABET[rotation];
	// if (notch_positions.find(position) != string::npos)
	// 	if (next)
	// 		next->rotate();
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


