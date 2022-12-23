#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>  

using namespace std; 

class File {
public:
	File();
	File(char* sFileName);
	
	void Write(string sText, int x);
	void Write(string sText);
	
	string Return_Buffor();
	string console_file_read();
	
private:
	string buffor;
};
