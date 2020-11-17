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

		int error_code;
		Plugboard* plugboard;
		Reflector* reflector;
		vector<Rotor*> rotor_list;
		string rotor_pos;

	public:
		// Constructor sets error code to 0.
		Machine();

		// Destructor deletes all components of the machine.
		~Machine();

		// configure the machine with the config list.
		int configure(list<string> config);

		// Encipher a string.
		void encipher(string& message);

		// Helper function to encipher an individual character.
		void encipher_char(char& ch);
};

#endif
