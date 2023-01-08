#pragma once
#include <iostream>
#include <string>
#include "Manage_File.h"

#define ALPHABET 26
using namespace std;

class Caesar {
	int shift;
	string key;
	char alphabet[ALPHABET]="";
	char alphabet_shifted[ALPHABET]="";
	string text_str;
public:
	Caesar();
	Caesar(string text, int action);

	void Encrypt(string text, string* o_buff);
	void Decrypt(string* o_buff);

	void shift_alphabet();
	void shift_alphabet(string key);

	void print_alphabet();
	void print_text();

	void initilizeAplhabet();
};