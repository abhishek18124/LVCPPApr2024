#include<iostream>

using namespace std;

void f(int n) {

	// base case

	if (n == 0) {

		// print nos. from 0 to 1 in dec. order

		return;

	}

	// recursive case

	// print nos. from n to 1 in the dec. order

	cout << n << " ";

	// 2. ask your friend to print nos. from n-1 to 1 in the decc. order

	f(n - 1);

}

int main() {

	int n;
	cin >> n;

	f(n);

	return 0;
}