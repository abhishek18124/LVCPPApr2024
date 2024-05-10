#include<iostream>

using namespace std;

int main() {

	char ch = 'A';

	cout << ch << endl;
	cout << (int)ch << endl;
	cout << static_cast<int>(ch) << endl << endl;

	ch = 'c';

	cout << ch << endl;
	cout << (int)ch << endl;
	cout << static_cast<int>(ch) << endl << endl;

	ch = '9';

	cout << ch << endl;
	cout << (int)ch << endl;
	cout << static_cast<int>(ch) << endl << endl;

	ch = '7';
	int x = ch; // implicit type-casting
	int y = ch - '0';
	cout << "x = " << x << " y = " << y << endl; // x = 55 y = 7

	return 0;
}