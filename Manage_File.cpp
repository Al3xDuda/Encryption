#include "Manage_File.h"
File::File() { buffor = ""; }
File::File(char* sFileName) {
	ifstream plik;
	//handle error by try and catch(do later)
	plik.open(sFileName);
	if(plik.good() == true) {
		string line;
		while(getline(plik, line)) {
			buffor += line;
			buffor += "\n";
		}
		plik.close();
		buffor.resize(buffor.length() - 1);
	}
	else {
		cout << "Error: File not found" << endl;
	}
}

string File::Return_Buffor() {
	return buffor;
}
void File::Write(string sText, int x) {
	ofstream plik;
	if(x==1) plik.open("dane_zaszyfrowane.txt");
	if(x == 2) plik.open("dane_odszyfrowane.txt");
	plik << sText;
	plik.close();
}

