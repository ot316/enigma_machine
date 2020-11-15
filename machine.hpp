#ifndef MACHINE_HPP
#define MACHINE_HPP

#include"rotor.hpp"
#include"reflector.hpp"
#include"plugboard.hpp"
#include<list>
#include<string>

using namespace std; 

class Machine {
	private:
		Plugboard* plugboard;
		Reflector* reflector;
		list<Rotor*> rotors;
		string rotor_pos;
	public:
		// constructor
		Machine(list<string> config);
		// Ddestructor
		~Machine();
	
		void encipher(string message);
};

#endif
