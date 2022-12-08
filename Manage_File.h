#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std; 

class File {
public:
	File();
	File(char* sFileName);
	string Return_Buffor();
	void Write(string sText,int x);
private:
	string buffor;
};



