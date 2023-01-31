#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include "Manage_File.h"

using namespace std;
class RC4 {
	int S[256];
	int T[256];
	size_t key_length;
	string text_str;
public:
	RC4(string text, int action);

	void Encrypt(string text, string* o_buff);
	void Decrypt(string* o_buff);

	void print_S();
	void print_T();
	void Init_T(string key);
	void Swap_S();
	void Init_S();

	void print_text();

};
