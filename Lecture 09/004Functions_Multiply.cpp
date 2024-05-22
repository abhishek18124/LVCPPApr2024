#include<iostream>

using namespace std;

int multiply(int a, int b) {

	int c = a * b;
	return c;

}

int main() {

	cout << multiply(2, 3) << endl;
	cout << multiply(4, 5) << endl;

	return 0;
}