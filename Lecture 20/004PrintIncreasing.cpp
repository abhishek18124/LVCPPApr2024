#include<iostream>

using namespace std;

void f(int n) {

	// base case

	if (n == 0) {

		// print nos. from 1 to 0 in inc. order

		return;

	}

	// recursive case

	// print nos. from 1 to n in the inc. order

	// 1. ask your friend to print nos. from 1 to n-1 in the inc. order

	f(n - 1);

	cout << n << " ";

}

int main() {

	int n;
	cin >> n;

	f(n);

	return 0;
}