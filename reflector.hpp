#ifndef REFLECTOR_HPP
#define REFLECTOR_HPP

#include"constants.hpp"

class Reflector {
	string mappings;
	public:
		int configure(string mapping);

		void encipher(char& ch);
};

#endif
