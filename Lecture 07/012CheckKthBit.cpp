#include<iostream>

using namespace std;

int main() {

	int n = 42;
	int k = 4;

	int mask = 1 << k;

	if ((n & mask) == 0) {
		cout << k << "th bit of " << n << " is not set" << endl;
	} else {
		cout << k << "th bit of " << n << " is set" << endl;
	}

	if (((n >> k) & 1) == 0) {
		cout << k << "th bit of " << n << " is not set" << endl;
	} else {
		cout << k << "th bit of " << n << " is set" << endl;
	}

	return 0;
}