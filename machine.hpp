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
		list<Rotor> rotors;
	public:
		// constructor
		Machine(list<string> config);
	
		void encipher(string message);
};

#endif
