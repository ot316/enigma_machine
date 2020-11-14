#include"machine.hpp"
#include<string>
#include<list>
#include<iostream>

using namespace std;

Machine::Machine(list<string> config) {
	string rotor_pos = config.back();
	cout << "rotor posiion is " << rotor_pos << endl;
	config.pop_back();

	list<string>::iterator it = config.begin();
	Plugboard plugboard(*it);
	advance(it,1);
	Reflector reflector(*it);
	int i = 0;
	while(++it != config.end()) {
		Rotor rotor(*it, rotor_pos[i++]);
		rotors.push_back(rotor);
	}
}

void Machine::encipher(string message) {
	
}

