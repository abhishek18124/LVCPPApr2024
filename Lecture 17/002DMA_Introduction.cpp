#include<iostream>

using namespace std;

int main() {

	int* ptr = new int;
	cout << ptr << endl;
	*ptr = 10;
	cout << *ptr << endl;

	delete ptr;

	ptr = new int;
	cout << ptr << endl;
	*ptr = 20;
	cout << *ptr << endl;

	char* chptr = new char;
	*chptr = 'A';
	cout << *chptr << endl;

	double* dptr = new double;
	*dptr = 3.14;
	cout << *dptr << endl;

	return 0;
}