#include "RC4.h"

RC4::RC4(string text, int action) {
	
	//key initilizer
	string key = "";
	cout << "input key: ";
	cin >> key;
	//open file to remember key
	File save_key;
	save_key.Write(key);
	//clear console
	system("cls");
	
	
	//initiate S and T
	key_length = key.length();
	this->Init_T(key);
	this->Init_S();

	//initiate text strings
	string text_buffor = "";
	string buffor = "";
	//open file
	File fin;
	//depending on action encrypt or decrypt
	switch(action) {
		//use encrypt on current object with text and write output to file
		case 1: this->Encrypt(text, &this->text_str); fin.Write(this->text_str, 1);  break;
		//use decrypt on current object with text and write output to file
		case 2: this->text_str = text; this->Decrypt(&buffor); fin.Write(buffor, 2); break;
	}
}
void RC4::Swap_S() {
	//hashing function
	int j = 0;
	for(int i{ 0 }; i < 256; i++) {
		j = (j + S[i] + T[i % key_length]) % 256;
		swap(S[i], S[j]);
	}
}
void RC4::Init_T(string key) {
	//initiate T
	for(int i{ 0 }; i < 256; i++) {
		this->T[i] = (int)key[i % key_length];
	}
}
void RC4::Init_S() {
	//initiate S
	for(int i{ 0 }; i < 256; i++) {
		this->S[i] = i;
	}
}
void RC4::Encrypt(string text, string* o_buff) {
	//encrypt text
	this->Init_S();
	this->Swap_S();
	int i{ 0 };
	int j{ 0 };
	//temporary variable to store letter/hex numbers
	char temp[3];
	int index{ 0 };
	//loop through text
	while(text[index]) {
		//increment i
		i = (i + 1) % 256;
		//increment j
		j = (j + S[i]) % 256;
		//swap S[i] and S[j]
		swap(S[i], S[j]);
		//get index of letter
		int wk = S[(S[i] + S[j]) % 256];
		//try to handle weird characters
		if((int)text[index] > 256) {
			sprintf(temp, "X%.2X", ((int)(text[index] - 256) ^ wk));
		}
		else sprintf(temp, "%.2X", ((int)text[index] ^ wk)); //convert number to hex
		//append to output string
		(*o_buff).append(temp);
		//increment index
		index++;
	}
	//save text
	text_str = *o_buff;
}
//convert hex to decimal number
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
//decrypt text
void RC4::Decrypt(string* o_buff) {
	int index{ 0 };
	//initilize S 
	this->Init_S();
	this->Swap_S();
	int i{ 0 };
	int j{ 0 };
	
	char temp[4];
	
	int  hexa = 0;
	//loop through text
	while(index < text_str.length()) {
		//increment i
		i = (i + 1) % 256;
		//increment j
		j = (j + S[i]) % 256;
		//swap S[i] and S[j]
		swap(S[i], S[j]);
		//get index of letter
		int wk = S[(S[i] + S[j]) % 256];
		//convert hex to decimal
		if((int)text_str[index] == 88) {
			index++;
			hexa = (hexToDecimal_C(text_str[index]) * 16 + hexToDecimal_C(text_str[index + 1])) + 256;
		}
		else hexa = (hexToDecimal_C(text_str[index]) * 16 + hexToDecimal_C(text_str[index + 1]));
		//save to temp
		sprintf(temp, "%c", hexa ^ wk); //convert number to hex
		//append to output string
		(*o_buff).append(temp);
		index += 2;
	}

}
//print S
void RC4::print_S() {
	for(int i{ 0 }; i < 256; i++) {
		cout << S[i] << setw(5);
		if(!((i + 1) % 10)) printf("\n");
	}
	printf("\n\n\n");
}
void RC4::print_T() {
	for(int i{ 0 }; i < 256; i++) {
		cout << S[i] << setw(5);
		if(!((i + 1) % 10)) printf("\n");
	}
	printf("\n\n\n");
}

void RC4::print_text() {
	cout << text_str;
}
