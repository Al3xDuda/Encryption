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
	if(x==1) plik.open("encrypt_file.txt");
	if(x == 2) plik.open("decrypt_file.txt");
	plik << sText;
	plik.close();
}
string File::console_file_read() {
	char file_name[50] = "";
	cout << "Remeber that the file cannot exceed 500 MB!\ntype_file_name:    ";
	cin >> file_name;
	system("cls");
	File nazwapliku(file_name);
	return nazwapliku.Return_Buffor();
}


void File:: Write(string sText) {
	std::ofstream plik("Key Log.txt", ios::app);

	// Check if the file was opened successfully
	if(!plik.is_open())
	{
		cerr << "Error: Unable to open file for writing." << std::endl;
		return;
	}
	time_t currentTime = time(nullptr);
	plik << ctime(&currentTime) << "\"" << sText <<"\"" <<endl;
	plik.close();
}
