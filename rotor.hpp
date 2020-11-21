#ifndef ROTOR_HPP
#define ROTOR_HPP

#include"constants.hpp"

class Rotor {
	private:
	string mappings;
	string reverse_mappings;
	string notch_positions;
	int reverseCharsMap[26];
	int rotation;
	// helper function to check the mappings provided are complete and valid.
	int checkMappings();

	public:
		// next rotor in chain.
		Rotor* next;

		// Constructor initialises next as null pointer.
		Rotor();

		// Enciphers a single character.
		void encipher(char& ch);

		// Reverse enciphers a single character.
		void reverseEncipher(char& ch);

		// helper function for reversing a string
		string reverse(string mapping);

		// Configure the rotor and check the mappings/
		int configure(string config, char starting_position);

		// Recursive function rotates the rotor and calls rotate on the 
		// next motor should a notch match up with the current position.
		// Base case is the final rotor whos next variable is nullptr.
		void rotate();
};

#endif
