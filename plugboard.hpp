#ifndef PLUGBOARD_HPP
#define PLUGBOARD_HPP

#include"constants.hpp"

class Plugboard {
	string mappings;
	public:
		// check the mapping for repeated characters and check if each character in the mapping has a pair.
		int configure(string mapping);

		// encipher a single character
		void encipher(char& ch);
};

#endif
