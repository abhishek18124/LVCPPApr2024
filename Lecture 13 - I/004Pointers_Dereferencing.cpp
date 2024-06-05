#include<iostream>

using namespace std;

int main() {

	int x = 516;
	char *xptr = (char*)&x;

	cout << "x = " << x << endl;
	cout << "*xptr = " << (int)*xptr << endl;


	int y = 12;
	char *yptr = (char*)&y;

	cout << "y = " << y << endl;
	cout << "*yptr = " << (int)*yptr << endl;

	return 0;
}