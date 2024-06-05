#include<iostream>

using namespace std;

int main() {

	int x = 10;

	int* xptr; // pointer declaration
	xptr = &x; // pointer assignment

	cout << "x = " << x << endl;
	cout << "sizeof(x) = " << sizeof(x) << endl;
	cout << "&x = " << &x << endl;
	cout << "xptr = " << xptr << endl;
	cout << "sizeof(&x) = " << sizeof(&x) << "B" << endl;
	cout << "sizeof(xptr) = " << sizeof(xptr) << "B" << endl;

	cout << endl;

	double y = 3.14;

	double* yptr = &y; // pointer initialization

	cout << "y = " << y << endl;
	cout << "sizeof(y) = " << sizeof(y) << endl;
	cout << "&y = " << &y << endl;
	cout << "yptr = " << yptr << endl;
	cout << "sizeof(&y) = " << sizeof(&y) << "B" << endl;
	cout << "sizeof(yptr) = " << sizeof(yptr) << "B" << endl;

	cout << endl;

	char ch = 'A';

	char* chptr = &ch; // pointer initialization

	cout << "ch = " << ch << endl;
	cout << "sizeof(ch) = " << sizeof(ch) << endl;
	cout << "&ch = " << &ch << endl;
	cout << "chptr = " << chptr << endl;
	cout << "sizeof(&ch) = " << sizeof(&ch) << "B" << endl;
	cout << "sizeof(chptr) = " << sizeof(chptr) << "B" << endl;

	cout << endl;

	return 0;
}