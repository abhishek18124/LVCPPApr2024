#include<iostream>

using namespace std;

int main() {

	const int y = 20;

	cout << y << endl;

	cout << y + 1 << endl;

	// y++; // error : you cannot increment read-only variable y

	// const int z; // error : uninitialized const 'z'

	return 0;
}