#include"errors.h"
#include"machine.hpp"
#include"rotor.hpp"
#include"reflector.hpp"
#include"plugboard.hpp"

#include<iostream>
#include<string>
#include<list>
#include<fstream>


//function to check user input
int checkUserInput(char ch);

//function to check and parse command line arguments
int parseArguments(list<string>& configs, int argc, char** argv);


int main(int argc, char** argv) {
	int error_code;
	list<string> machine_config;

	error_code = parseArguments(machine_config, argc, argv);
	if(error_code) return error_code;

	Machine enigma_machine;
	error_code = enigma_machine.configure(machine_config);
	if(error_code) return error_code;

	char ch;
	while(cin >> ws >> ch){
		
		error_code = checkUserInput(ch);
		if(error_code) return error_code;

		enigma_machine.encipher(ch);
		cout << ch;
	}
	return error_code;
}


int parseArguments(list<string>& configs, int argc, char** argv) {
	if(argc < 4) {
		cerr << "Insufficient number of parameters, usage is: enigma plugboard-file reflector-file (<rotor-file>)* rotor-positions\n";
		return(INSUFFICIENT_NUMBER_OF_PARAMETERS);
	}

	for(auto i = 1; i < argc; i++) {
		ifstream argument_file;
		argument_file.open(argv[i]);
		if(argument_file.fail() || !argument_file.is_open()) {
			cerr << "Configuration file '" << argv[i] << "' failed to open.\n";
			return ERROR_OPENING_CONFIGURATION_FILE;
		}

		char ch;
		while (argument_file.get(ch)) {
			if (!isdigit(ch) && ch != ' ' && ch != '\n' && ch != '-' && ch != '\t' && ch != 13) {
				cerr << "The file '" << argv[i] << "' has a non-numeric character.\n";
				return NON_NUMERIC_CHARACTER;
			}
		}
		// Close and reopen file to check the numbers are valid
		argument_file.close();
		argument_file.open(argv[i]);
		int number;
		int alphabet_length = ALPHABET.size();
		string mapping = {};
		while (argument_file >> number) {
			if (number < 0 || number >= alphabet_length) {
				cerr << "Argument '" << argv[i] << "' has invalid index.\n";
				return INVALID_INDEX;
			}
			else {
				char letter = static_cast<char>(number) + 65;
				mapping = mapping + letter;
			}
		}
		configs.push_back(mapping);
	}
	return NO_ERROR;
}


int checkUserInput(char ch) {
	if(ch < 'A' || ch > 'Z'){
		cerr << "Invalid Input Character: '" << ch << "'. Inputs must be upper case letters A-Z.\n";
		return INVALID_INPUT_CHARACTER;
	}
	return NO_ERROR;
}