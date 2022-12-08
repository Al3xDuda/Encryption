#include "RC4.h"
#include "Manage_File.h"
#define KEY "mention"
using namespace std;
//#define SHOW 

int main() {
	char* test = new char[256];
	cout << "wpisz nazwe pliku ktory chcesz zaszyfrowac: ";
	cin >> test;
	File nazwapliku(test);
	string buffor = nazwapliku.Return_Buffor();
#ifdef SHOW
	cout << nazwapliku.Return_File_Type() << endl;
	cout << endl;
	cout << buffor << endl;
#endif 
	RC4 var = RC4(buffor, KEY);
#ifdef SHOW
	var.print_S();
	var.print_T();
	for(int i = 0; i < nazwapliku.Return_Buffor().length() + 1; i++) {
		printf("%c ", buffor[i]);
	}
#endif
	return 0;
}

