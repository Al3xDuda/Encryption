#include "RC4.h"
#include "Manage_File.h"

using namespace std;

int main() {
	int method = 0;
	cout << "choose coding method: \n";
	cout << "1-RC4\n";
	cin >> method;
	system("cls");
	switch(method) {
		case 1:break;
		default: cout << "None actions match your input\n"; return 0;
	}

	int input_type = 0;
	cout << "Do you wish to:\n1-input text\n2-read from file\n";
	cin >> input_type;
	system("cls");
	switch(method) {
		case 1:break; case 2:break;
		default: cout << "None actions match your input\n"; return 0;;
	}

	cout << "1-encode\n2-decode\n";
	int action = 0;
	cin >> action;
	switch(method) {
		case 1:break; case 2:break;
		default: cout << "None actions match your input\n"; return 0;
	}
	system("cls");

	switch(method) {
		case 1: RC4(input_type, action); break;
	}
	return 0;
}
