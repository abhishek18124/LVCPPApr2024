#include<iostream>

using namespace std;

int main() {

	int n = 15;

	int mask = n - 1;

	// clear the rightmost set bit of n

	if ((n & mask) == 0) {
		cout << n << "  is a power of 2" << endl;
	} else {
		cout << n << " is not a power of 2" << endl;
	}

	return 0;
}