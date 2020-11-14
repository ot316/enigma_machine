
#ifndef CIPHER_HPP
#define CIPHER_HPP

#include"errors.h"
#include <string>
#include<iostream>

using namespace std;

const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int ALPHABET_LENGTH = 26;

class Cipher {
	string alphabet = ALPHABET;
	string mapping;
	public:
		void encipher(char& ch);

		char to_letter(int num);

		int to_number(char ch);
};

#endif


