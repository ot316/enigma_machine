#ifndef PLUGBOARD_HPP
#define PLUGBOARD_HPP

#include"cipher.hpp"

class Plugboard:public Cipher {
	private:
	string alphabet;
	string mappings;

	public:
	
		//constructor
		Plugboard(string mapping);

		void check_config(string mappings);
};

#endif
