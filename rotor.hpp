#ifndef ROTOR_HPP
#define ROTOR_HPP

#include"constants.hpp"

class Rotor {
	private:
	string mappings;
	string notch_positions;
	int rotation;

	int checkMappings();

	public:
		Rotor* next;

		// Constructor initialises next as null pointer
		Rotor();

		// Enciphers a single character
		void encipher(char& ch);

		// Reverse enciphers a single character, after reflector
		void reverseEncipher(char& ch);


		//check the mappings provided are valid
		int configure(string config, char starting_position);

		//rotate
		void rotate();
};

#endif
