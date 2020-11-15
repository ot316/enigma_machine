#include"machine.hpp"
#include<string>
#include<list>
#include<iostream>

using namespace std;

Machine::Machine(list<string> config) {
	rotor_pos = config.back();
	cout << "rotor posiion is " << rotor_pos << endl;
	config.pop_back();

	list<string>::iterator it = config.begin();
	plugboard = new Plugboard(*it);
	advance(it,1);

	reflector = new Reflector(*it);
	auto i = 0u;
	while(++it != config.end()) {
		Rotor* rotor;
		rotor = new	Rotor(*it, rotor_pos[i++]);
		rotors.push_back(rotor);
	}
}

// Delete all components of the machine.
Machine::~Machine(){
	delete plugboard;
	delete reflector;
	for(list<Rotor*>::iterator rotor = rotors.begin(); rotor != rotors.end(); rotor++) {delete *rotor;}
}



void Machine::encipher(string message) {
	
}

