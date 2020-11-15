#ifndef ROTOR_HPP
#define ROTOR_HPP

#include"cipher.hpp"

class Rotor:public Cipher {
	private:
	int initial_offset;
	string config;
	string mappings;
	string alphabet;
	string notch_positions;
	int notch_position;
	int rotations;
	bool rotate_next_rotor = 0;

	public:
	
		//constructor
		Rotor(string mapping, char starting_position);

		//reset the rotor to its original state before any rotations
		void reset();
		
		//check the mappings provided are valid
		void check_mappings(string mappings);

		//rotate
		void rotate(char offset);
};

#endif
