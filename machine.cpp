#include"machine.hpp"
#include<string>
#include<list>
#include<iostream>

using namespace std;

Machine::Machine() {
	error_code = NO_ERROR;
	plugboard = nullptr;
	reflector = nullptr;
}

Machine::~Machine(){
	delete plugboard;
	delete reflector;
	for (auto i = 0u; i << rotor_list.size(); i++) 
		delete rotor_list[i];
}

int Machine::configure(list<string> config) {
	// read rotor position config.
	rotor_pos = config.back();
	config.pop_back();

	// create plugboard.
	list<string>::iterator it = config.begin();
	plugboard = new Plugboard;
	error_code = plugboard->configure(*it++);
	if(error_code) return error_code;

	// create reflector.
	reflector = new Reflector;
	error_code = reflector->configure(*it);
	if(error_code) return error_code;

	// create as many rotos as necessary.
	auto i = 0u;
	while(++it != config.end()) {
		Rotor* rotor;

		if(!rotor_pos[i]){
			cerr << "Insufficient starting positions for the given number of rotors." << endl;
			return NO_ROTOR_STARTING_POSITION;
		}

		rotor = new	Rotor;
		error_code = rotor->configure(*it, rotor_pos[i++]);
		if(error_code) return error_code;
		rotor_list.push_back(rotor);
	}

	// point each rotor to the next rotor
	for (auto i = 0u; i < rotor_list.size(); i++)
		rotor_list[i]->next = rotor_list[i+1];

	return error_code;
}

void Machine::encipher(string& message) {
	for (char& ch: message) {
		encipher_char(ch);
	}
}

void Machine::encipher_char(char& ch) {

	plugboard->encipher(ch);

	for (auto i = 0u; i < rotor_list.size(); i++) {
		rotor_list[i]->encipher(ch);
	}

	reflector->encipher(ch);

	for (int i = rotor_list.size()-1; i >= 0; i--) {
		rotor_list[i]->reverseEncipher(ch);
	}

	plugboard->encipher(ch);

	// Recursive function call, base case is the final rotor whos next variable is nullptr
	if(!rotor_list.empty())
		rotor_list[0]->rotate();
}

