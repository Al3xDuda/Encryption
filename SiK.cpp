#include "RC4.h"
#include "Manage_File.h"
#include "Caesar.h"
#define KEY "mention"

using namespace std;

int main() {
	//use try and catch to handle errors
	try {
		//input an encryption method
		int method = 0;
		cout << "choose coding method: \n";
		cout << "1-RC4\n2-Caesar\n";
		cin >> method;
		//clear console
		system("cls");
		//hnadle unwanted input
		switch(method) {
			case 1:break;
			case 2:break;
			//throw an exception if the input does not match either 1 or 2
			default: throw runtime_error("Error: Invalid coding method.");
		}
		
		
		//choose input method
		int input_type = 0;
		cout << "Do you wish to:\n1-input text\n2-read from file\n";
		cin >> input_type;
		//ignore whitespace signs in order to read whole line with getline
		cin.ignore(1000, '\n');
		//clear console
		system("cls");
		//initiate a string to store input
		string text_buffor;
		//handle unwanted input
		switch(input_type) {
			case 1: {
				cout << "input text: \n";
				//read text with getline and store it in text_buffor
				getline(cin, text_buffor);
				cout << text_buffor;
				//clear console
				system("cls");
				break;
			};
			case 2: {
				File fin;
				//read text from file and store it in text_buffor
				text_buffor = fin.console_file_read();
				break;
			};
			default: 	
				// throw an exception if the input does not match either 1 or 2
				throw runtime_error("Error: Invalid input type.");
			}
		
		
		cout << "1-encode\n2-decode\n";
		int action = 0;
		cin >> action;
		system("cls");
		switch(action) {
			case 1:break; case 2:break;
			default:
				// throw an exception if the input does not match either 1 or 2
				throw runtime_error("Error: Invalid action.");
			}
		
		
		//initiate cipher function
		switch(method) {
			case 1: RC4(text_buffor, action); break;
			case 2:Caesar(text_buffor, action); break;
		}
	}
	//catch exceptions
	catch(const exception& e) {
		cout << e.what()<<endl;
	}
	return 0;
}
