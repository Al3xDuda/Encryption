#include "Manage_File.h"

//initiate a file object
File::File() { buffor = ""; }

//initiate a file object with a file name
File::File(char* sFileName) {
	//open a file with a given name
	ifstream plik;
	//handle error by try and catch
	try {
		plik.open(sFileName);
		if(plik.good() == true) {
			//read the file line by line and store it in buffor
			string line;
			while(getline(plik, line)) {
				buffor += line;
				buffor += "\n";
			}
			//close the file
			plik.close();
			//delete last next line sign
			buffor.resize(buffor.length() - 1);
		}
		else throw runtime_error("Error: File not found.");
	}
	//catch exceptions
	catch(const exception& e) {
		// print the error message
		cout << e.what() << endl;
	}
}

//return buffor
string File::Return_Buffor() {
	return buffor;
}

//write to file
void File::Write(string sText, int x) {
	//open a file
	ofstream plik;
	//depending on x value open a different file
	if(x==1) plik.open("encrypt_file.txt");
	if(x == 2) plik.open("decrypt_file.txt");
	//write to file
	plik << sText;
	//close the file
	plik.close();
}

//open a file and read it
string File::console_file_read() {
	//initiate a filename string
	char file_name[50] = "";
	cout << "type_file_name: ";
	cin >> file_name;
	//clear console
	system("cls");
	//initiate a file object with a given file name
	File nazwapliku(file_name);
	//return the file content
	return nazwapliku.Return_Buffor();
}

//function to save used keys
void File:: Write(string sText) {
	//open a file
	std::ofstream plik("Key Log.txt", ios::app);
	// Check if the file was opened successfully
	if(!plik.is_open())
	{
		cerr << "Error: Unable to open file for writing." << std::endl;
		return;
	}
	//initiate date
	time_t currentTime = time(nullptr);
	//write to file
	plik << ctime(&currentTime) << "\"" << sText <<"\"" <<endl;
	//close file
	plik.close();
}
