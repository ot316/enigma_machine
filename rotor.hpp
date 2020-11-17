#ifndef ROTOR_HPP
#define ROTOR_HPP

#include"cipher.hpp"

class Rotor:public Cipher {
	private:
	int initial_offset;
	string config;
	string alphabet = ALPHABET;
	string mappings;
	string notch_positions;
	int notch_position;
	int rotation;
	bool rotate_next_rotor = 0;

	public:
		void encipher(char& ch);

		void reverse_encipher(char& ch);

		//check the mappings provided are valid
		int configure(string config, char starting_position);

		//rotate
		void rotate();
};

#endif
