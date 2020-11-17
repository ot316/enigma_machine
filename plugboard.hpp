#ifndef PLUGBOARD_HPP
#define PLUGBOARD_HPP

#include"cipher.hpp"

class Plugboard:public Cipher {
	private:
	string alphabet;
	string mappings;

	public:
		int configure(string mapping);

		void encipher(char& ch);
};

#endif
