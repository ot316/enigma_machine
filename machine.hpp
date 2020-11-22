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

		// point each rotor to the next rotor, except the last one.
		void linkRotors();

		// Encipher an individual character 
		// by passing it through each of the components in sequence
		// and then back again.
		void encipher(char& ch);
};

#endif
