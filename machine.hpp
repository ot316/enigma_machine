#ifndef MACHINE_HPP
#define MACHINE_HPP

#include"rotor.hpp"
#include"reflector.hpp"
#include"plugboard.hpp"
#include<list>
#include<string>
#include<vector>

using namespace std; 

class Machine {
	private:
		Plugboard* plugboard;
		Reflector* reflector;
		vector<Rotor*> rotor_list;
		string rotor_pos;
		int error_code = NO_ERROR;
	public:
		// Ddestructor
		~Machine();

		int configure(list<string> config);

		void encipher(string& message);

		void encipher_char(char& ch);
};

#endif
