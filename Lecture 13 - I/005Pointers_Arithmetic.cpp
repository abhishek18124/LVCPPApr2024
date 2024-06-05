#include<iostream>

using namespace std;

int main() {

	int x = 10;
	int* xptr = &x;

	cout << "xptr = " << xptr << endl;

	xptr++;

	cout << "xptr = " << xptr << endl;

	int y = 20;
	int* yptr = &y;

	cout << "yptr = " << yptr << endl;

	yptr = yptr + 2;

	cout << "yptr = " << yptr << endl;

	return 0;
}