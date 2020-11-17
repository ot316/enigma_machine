#ifndef REFLECTOR_HPP
#define REFLECTOR_HPP

#include"constants.hpp"

class Reflector {
	string mappings;
	public:
		// check the mapping for repeated characters and check if the mapping is complete.
		int configure(string mapping);

		// encipher a single character
		void encipher(char& ch);
};

#endif
