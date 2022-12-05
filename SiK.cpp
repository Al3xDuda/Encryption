#include <iostream>

#include "Read_File.h"
using namespace std;

int main() {
	char* test = new char[10];
	cin >> test;
	Read_File nazwapliku = Read_File(test, 1);
	string buffor = nazwapliku.Return_Buffor();
	cout << endl;
	cout << buffor << endl;

	
	
}