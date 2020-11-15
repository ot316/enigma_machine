#ifndef REFLECTOR_HPP
#define REFLECTOR_HPP

#include"cipher.hpp"

class Reflector:public Cipher {
	private:
	string alphabet;
	string mappings;
	public:
	
		//constructor
		Reflector(string mapping);
};

#endif
