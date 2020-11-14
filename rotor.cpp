#include"rotor.hpp"
#include<string>
#include<iostream>
#include<algorithm>

Rotor::Rotor(string config, char starting_position) {
	rotations = 0;
	mappings = config.substr(0, ALPHABET_LENGTH);
	check_mappings(mappings);	
	notch_positions = config.substr(ALPHABET_LENGTH, string::npos);
	cout << "Rotor is initialised with " << mappings << " and notch positions " << notch_positions << ". Initial position is " << starting_position << endl;
	rotate(starting_position);
}

void Rotor::reset() {
	rotate(initial_offset);
}

void Rotor::check_mappings(string mappings) {
	for (char i = 'A'; i <= 'Z'; i++) {
		if (mappings.find(i) == string::npos) {
			cerr << "The rotor config file contains an invalid mapping\n";
			exit(INVALID_ROTOR_MAPPING);
		}
	}
}

void Rotor::rotate(char offset) {
	int offset_count  = to_number(offset);
	rotations = rotations + offset_count;

	if (rotations > ALPHABET_LENGTH) 
		rotations = rotations - ALPHABET_LENGTH;

	offset = mappings.size() - offset_count;
	mappings = mappings.substr(offset_count, string::npos) + mappings.substr(0, offset_count);
	cout << "New mappings are " << mappings << endl;

	rotate_next_rotor = (notch_positions.find(to_letter(rotations)) != string::npos) ? true : false;
	cout << "rotate next rotor? " << rotate_next_rotor << endl;
}


