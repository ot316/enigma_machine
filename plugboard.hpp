#ifndef PLUGBOARD_HPP
#define PLUGBOARD_HPP

#include"constants.hpp"

class Plugboard {
	string mappings;
	public:
		int configure(string mapping);

		void encipher(char& ch);
};

#endif
