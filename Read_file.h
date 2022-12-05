#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std; 



class Read_File {

public:
	Read_File();
	Read_File(char* sFileName, int file_type);
	string Return_Buffor();
private:
	string buffor;
};



