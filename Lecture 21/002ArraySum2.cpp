#include<iostream>

using namespace std;

int f(int X[], int i) {

	// base case

	// if (i == 0) {

	// 	// find the sum(X[0...0]) = sum({X[0]})

	// 	return X[0];

	// }

	if (i == -1) {

		// find the sum(X[0...-1]) = sum({})
		return 0;

	}

	// recursive case

	// find the sum(X[0...i])

	// 1. ask your friend to find the sum(X[0...i-1])

	int A = f(X, i - 1);

	return A + X[i];

}

int main() {

	int X[] = {1, 2, 3, 4, 5};
	int n = sizeof(X) / sizeof(int);

	cout << f(X, n - 1) << endl;

	return 0;
}