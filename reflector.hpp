#ifndef REFLECTOR_HPP
#define REFLECTOR_HPP

#include"cipher.hpp"

class Reflector:public Cipher {
	private:
	string alphabet = ALPHABET;
	string mappings;

	public:
		int configure(string mapping);

		void encipher(char& ch);
};

#endif
