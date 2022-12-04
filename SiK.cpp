#include <iostream>

using namespace std;

int main() {
	char* test = new char[10];
	cin >> test;
	while(*test) {// ASCII check
		printf("%d ", *test++);
	}
}