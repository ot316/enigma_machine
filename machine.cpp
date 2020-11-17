#include"machine.hpp"
#include<string>
#include<list>
#include<iostream>

using namespace std;


// Destructor deletes all components of the machine.
Machine::~Machine(){
	delete plugboard;
	delete reflector;
	for (auto i = 0u; i << rotor_list.size(); i++) 
		delete rotor_list[i];
}

// configure the machine with the config list
int Machine::configure(list<string> config) {
	rotor_pos = config.back();
	// cout << "rotor posiion is " << rotor_pos << endl;
	config.pop_back();

	list<string>::iterator it = config.begin();
	plugboard = new Plugboard;
	error_code = plugboard->configure(*it++);
	if(error_code) return error_code;

	reflector = new Reflector;
	error_code = reflector->configure(*it);
	if(error_code) return error_code;

	auto i = 0u;
	while(++it != config.end()) {
		Rotor* rotor;

		if(!rotor_pos[i]){
			cerr << "Insufficient starting positions for the given number of rotors." << endl;
			return NO_ROTOR_STARTING_POSITION;}

		rotor = new	Rotor;
		error_code = rotor->configure(*it, rotor_pos[i++]);
		char ch = 'l';
		rotor_list.push_back(rotor);
	}

	// point each rotor to the next rotor
	for (auto i = 0u; i < rotor_list.size()-1; i++)
		rotor_list[i]->next = rotor_list[i+1];

	return error_code;
}

void Machine::encipher(string& message) {
	for (char& ch: message) {
		encipher_char(ch);
	}
}

void Machine::encipher_char(char& ch) {
	// cout << ' ' << ch << ' ';
	plugboard->encipher(ch);
	// cout << ' ' << ch << ' ';
	for (auto i = 0u; i < rotor_list.size(); i++) {
		rotor_list[i]->encipher(ch);
		// cout << ch;
	}

	reflector->encipher(ch);
	// cout << ' ' << ch << ' ';

	for (int i = rotor_list.size()-1; i >= 0; i--) {
		rotor_list[i]->reverse_encipher(ch);
		// cout << ch;
	}
	
	// cout << ' ' << ch << ' ';
	plugboard->encipher(ch);
	// cout << ' ' << ch << ' ';
	// cout << endl;
	rotor_list[0]->rotate();
}

