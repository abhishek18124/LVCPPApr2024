#include<iostream>

using namespace std;

namespace add {

int f(int a, int b) {
	return a + b;
}

};

namespace mul {

int f(int a, int b) {
	return a * b;
}

};

int f(int a, int b) {
	return a - b;
}

int main() {

	cout << add::f(2, 3) << endl; // f in add namespace is called
	cout << mul::f(2, 3) << endl; // f in mul namespace is called
	cout << f(10, 3) << endl; // cout << ::f(10, 3); // f in global namespace is called

	return 0;
}