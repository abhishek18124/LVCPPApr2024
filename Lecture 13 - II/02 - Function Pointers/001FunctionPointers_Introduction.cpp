#include<iostream>

using namespace std;

void greet() {
	cout << "namaste" << endl;
}

int add(int a, int b) {
	return a + b;
}

bool ascending(int a, int b) {
	return a > b; // return true if a > b otherwise return false
}

int main() {

	cout << (void*)&greet << endl;
	cout << (void*)greet << endl << endl;
	void (*gptr)() = &greet;
	cout << (void*)gptr << endl;

	greet();
	(*greet)();
	(*gptr)();
	gptr();

	cout << (void*)&add << endl;
	cout << (void*)add << endl << endl;
	int (*aptr)(int, int) = &add;
	cout << (void*)aptr << endl;

	cout << add(2, 3) << endl;
	cout << (*add)(2, 3) << endl;
	cout << (*aptr)(2, 3) << endl;
	cout << aptr(2, 3) << endl << endl;

	cout << (void*)&ascending << endl;
	cout << (void*)ascending << endl;
	bool (*ascptr)(int, int) = &ascending;
	cout << (void*)ascptr << endl;

	cout << ascending(3, 1) << endl;
	cout << (*ascending)(3, 1) << endl;
	cout << (*ascptr)(3, 1) << endl;
	cout << ascptr(3, 1) << endl;

	return 0;
}