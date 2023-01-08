#include "Caesar.h"

#define DEBUG_CAESAR
//initiate empty object
Caesar::Caesar() {
	key = "";
	text_str = "";
	shift = 0;
	initilizeAplhabet();
}
//initiate object with text and action
Caesar::Caesar(string text, int action) {
	//initiate alphabet
	initilizeAplhabet();
	//input shift
	cout << "Input shift: ";
	cin >> shift;
	cout << "Do you wish to use a key? 1-True/0-False\n";
	int key_choice = 0;
	cin >> key_choice;
	//alter alphabet correspodnig to key
	if(key_choice == 1) {
		string key = "";
		cout << "input key: ";
		cin >> key;
		File save_key;
		save_key.Write(key + " " + to_string(shift));
		system("cls");
		shift_alphabet(key);
	}
	else shift_alphabet();
#ifdef DEBUG_CAESAR
	for(int i = 0; i < ALPHABET; i++) {
		cout << alphabet_shifted[i] << " ";
	}
	cout << endl;
	for(int i = 0; i < ALPHABET; i++) {
		cout << alphabet[i] << " ";
	}
#endif
		string buffor = "";
		//open file
		File fin;
		switch(action) {
			//encrypt text and write to file
		case 1: this->Encrypt(text, &this->text_str); fin.Write(this->text_str, 1);  break;
			//decrypt text and write to file
		case 2: this->text_str = text; this->Decrypt(&buffor); fin.Write(buffor, 2); break;
		}
}
void Caesar::Encrypt(string text, string* o_buff) {
	int j = 0;
	//loop through text
	while(text[j]) {
		int flag = 0;
		//if character is not a letter write it to output
		if(!isalpha(text[j])) {
			*o_buff += text[j];
			j++;
			continue;
		}
		else {
			//if character is uppercase flag it in order to write it back in uppercase
			if(text[j] >= 'A' && text[j] <= 'Z') {
				text[j] = text[j] + 'a' - 'A';
				flag = 1;
			}
			//loop through alphabet
			for(int i = 0; i < ALPHABET; i++) {
				//if character is found in alphabet
				if(text[j] == alphabet[i]) {
					//write shifted character to output
					//depending on flag value write uppercase or lowercase
					(*o_buff) += (flag?(alphabet_shifted[i]-'a'+'A'):alphabet_shifted[i]);
					break;
				}
			}
		}
		//increment j
		j++;
	}
}
//decrypt text
void Caesar::Decrypt(string* o_buff) {
	int j = 0;
	//loop through text
	while(text_str[j]){
		int flag = 0;
		//if character is not a letter write it to output
		if(!isalpha(text_str[j])) {
			*o_buff += text_str[j];
			j++;
			continue;
		}
		else {
			//if character is uppercase flag it in order to write it back in uppercase
			if(text_str[j] >= 'A' && text_str[j] <= 'Z') {
				text_str[j] = text_str[j] + 'a' - 'A';
				flag = 1;
			}
			//loop through alphabet
			for(int i = 0; i < ALPHABET; i++) {
				if(text_str[j] == alphabet_shifted[i]) {
					//write shifted character to output
					//depending on flag value write uppercase or lowercase
					(*o_buff) += (flag?(alphabet[i]-'a'+'A'):alphabet[i]);
					break;
				}
			}
		} 
		//increment j
		j++;
	}
}
void Caesar::print_text() {
	cout << text_str;
}
void Caesar::initilizeAplhabet() {
	for(int i = 0; i < ALPHABET; i++) {
		alphabet[i] = i + 'a';
	}
}
void Caesar::shift_alphabet() {
	for(int i = 0; i<ALPHABET; i++) {
		alphabet_shifted[(i + shift) % ALPHABET] = alphabet[i];
	}
}
void Caesar::shift_alphabet(string key) {
	int len = 0;
	int flag = 0;
	//write key after shift without reapeating characters
	for(int i = 0; i < key.length(); i++) {
		for(int j = 0; j < ALPHABET; j++) {
			if(key[i] == alphabet_shifted[j]) flag = 1;
		}
		//if letter reapeats it is flagged
		//if it is not flagged write it to alphabet
		if(flag == 1) {
			flag = 0;
			continue;
		};
		alphabet_shifted[(i + shift) % ALPHABET] = key[i];
		len++;
	}
	//fill rest of alphabet with letters not in key
	//starting from end of key
	int iter = shift + len;
	for(int j = 0; j < ALPHABET; j++) {
		for(int i = 0; i < ALPHABET; i++) {
			if(alphabet_shifted[(i + shift + len) % ALPHABET] == alphabet[j]) {
				flag = 1; break;
			};
		}
		if(flag) {
			flag = 0;
			continue;
		}
		alphabet_shifted[(iter++) % ALPHABET] = alphabet[j];
	}
}