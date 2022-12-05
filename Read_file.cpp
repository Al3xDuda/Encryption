#include "Read_File.h"
Read_File::Read_File(char* sFileName, int file_type) {
	ifstream plik;
	plik.open(sFileName);
	if(plik.good() == true) {
		string line;
		while(getline(plik, line)) {
			buffor += line;
			buffor += "\n";
		}
		plik.close();
	}
	else {
		cout << "Error: File not found" << endl;
	}
}

string Read_File::Return_Buffor() {
	return buffor;
}



