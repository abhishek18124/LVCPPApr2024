#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	if (n == 0 || n == 1) {

		cout << n << endl;

	} else {

		// n >= 2

		int a = 0; // to store the 0th fib. no.
		int b = 1; // to store the 1st fib. no.

		int i = 2;

		while (i <= n) { // we'll enter into the look exactly n-1 times

			int c = a + b;
			a = b;
			b = c;

			i = i + 1;

		}

		cout << b << endl;

	}

	// (n-1).c ~ nc = O(n)


	return 0;
}