#include<iostream>
#include"errors.h"
#include<string>
#include<list>
#include<fstream>
#include<stdexcept>
#include"machine.hpp"
#include"rotor.hpp"
#include"reflector.hpp"
#include"plugboard.hpp"


//function to check and parse arguments
list<string> parseArguments(int argc, char** argv);

int main(int argc, char** argv) {
	list<string> config = parseArguments(argc, argv);
	list<string>::iterator ro;
	for (ro = config.begin();
		 ro != config.end();
		 ro++) {
		cout << *ro << endl;
		}
	Machine Machine(config);
	return NO_ERROR;
}

list<string> parseArguments(int argc, char** argv) {
	list<string> configs;

	if(argc < 5) {
		cerr << "Insufficient number of parameters";
		exit(INSUFFICIENT_NUMBER_OF_PARAMETERS);
		}

	for(int i = 1; i < argc; i++) {
		ifstream arg;
		arg.open(argv[i]);
		if(arg.fail()) {
			cerr << "Configuration file failed to open.";
				exit(ERROR_OPENING_CONFIGURATION_FILE);
		}

		char ch;
		while (arg.get(ch)) {
			if (!isdigit(ch) && ch != ' ' && ch != '\n' && ch != '-') {
				cerr << "The argument '" << argv[i] << "' has a non numeric character.\n";
				exit(NON_NUMERIC_CHARACTER);
			}
		}
		arg.close();
		arg.open(argv[i]);
		int number;
		int alphabet_length = ALPHABET.size();
		string mapping = {};
		while (arg >> number) {
			if (number < 0 || number > alphabet_length) {
				cerr << "Argument '" << argv[i] << "' has invalid index.\n";
				exit(INVALID_INDEX);
			}
			else {
				char letter = static_cast<char>(number) + 65;
				mapping = mapping + letter;
			}
		}
		configs.push_back(mapping);
	}
	return configs;
}
