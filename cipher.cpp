#include "cipher.hpp"

// void Cipher::encipher(char& ch) {
// 	int index = alphabet.find(ch);
// 	ch = this->mappings[index];
// }

int Cipher::to_number(char ch) {
	return static_cast<int>(ch - 'A');
}

char Cipher::to_letter(int num) {
	return static_cast<char>(num) + 'A';
}
	
