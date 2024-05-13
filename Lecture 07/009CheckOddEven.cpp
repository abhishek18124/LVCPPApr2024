#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int rightMostBit = n & 1;
	cout << rightMostBit << endl;

	if ((n & 1) == 1) {
		cout << n << " is odd" << endl;
	} else {
		cout << n << " is even" << endl;
	}


	if (n & 1) {
		cout << n << " is odd" << endl;
	} else {
		cout << n << " is even" << endl;
	}

	return 0;
}