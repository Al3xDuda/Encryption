#include "RC4.h"

RC4::RC4(string text, string key) {
	key_length = key.length();
	File fout;
	this->Init_T(key);
	this->Init_S();
	Encrypt(text, &text_str);
	fout.Write(text_str, 1);
	string buffor = "";
	Decrypt(&buffor);
	fout.Write(buffor,2);
}
void RC4::Swap_S() {
	int j = 0;
	for(int i{ 0 }; i < 256; i++) {
		j = (j + S[i] + T[i % key_length]) % 256;
		swap(S[i], S[j]);
	}
}
void RC4::Init_T(string key) {
	for(int i{ 0 }; i < 256; i++) {
		this->T[i] = (int)key[i % key_length];
	}
}
void RC4::Init_S() {
	for(int i{ 0 }; i < 256; i++) {
		this->S[i] = i;
	}
}
void RC4::Encrypt(string text,string* o_buff) {
	this->Init_S();
	this->Swap_S();
	int i{ 0 };
	int j = 0;
	char temp[100];
	int index{ 0 };
	int flag = 0;
	while(text[index]) {
		if(index == 2800 || flag ) {
			flag = 1;
		}
		i = (i + 1) % 256;
		j = (j + S[i]) % 256;
		swap(S[i], S[j]);
		int wk = S[(S[i] + S[j]) % 256];
		sprintf(temp,"%.2X", ((int)text[index] ^ wk)); //convert number to hex
		(*o_buff).append(temp);
		index++;
	}
	text_str = *o_buff;
}
int hexToDecimal_C(char hex) {
	int decimal = 0;
	if(hex >= '0' && hex <= '9') {
		decimal = hex - '0';
	}
	else if(hex >= 'A' && hex <= 'F') {
		decimal = hex - 'A' + 10;
	}
	else if(hex >= 'a' && hex <= 'f') {
		decimal = hex - 'a' + 10;
	}
	return decimal;
}
int hexToDecimal(string hex) {
	int decimal = 0;
	int power = 1;
	for(int i = hex.length() - 1; i >= 0; i--) {
		decimal += hexToDecimal_C(hex[i]) * power;
		power *= 16;
	}
	return decimal;
}
void RC4::Decrypt( string* o_buff) {
	int index{ 0 };
	this->Init_S();
	this->Swap_S();
	int i = 0;
	int j = 0;
	char temp[100];
	int flag = 0;
	while(index<text_str.length()) {
		if(index >= 5500) {
			memset(&temp[0], 0, sizeof(temp));
			flag = 1;
		}
		i = (i + 1) % 256;
		j = (j + S[i]) % 256;
		swap(S[i], S[j]);
		int wk = S[(S[i] + S[j]) % 256];
		int hexa = (hexToDecimal_C(text_str[index])*16+ hexToDecimal_C(text_str[index+1]));
		sprintf(temp, "%c", hexa ^ wk); //convert number to hex
		(*o_buff).append(temp);
		index+=2;
	}
	
}
void RC4::print_S() {
	for(int i{ 0 }; i < 256; i++) {
		cout << S[i] << setw(5);
		if(!((i+1) % 10)) printf("\n");
	}
	printf("\n\n\n");
}
void RC4::print_T() {
	for(int i{ 0 }; i < 256; i++) {
		cout << S[i] << setw(5);
		if(!((i+1) % 10)) printf("\n");
	}
	printf("\n\n\n");
}
