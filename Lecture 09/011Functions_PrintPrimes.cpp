#include<iostream>
#include<cmath>

using namespace std;

bool isPrime(int n) {

	int sqRoot = sqrt(n);

	for (int i = 2; i <= sqRoot; i++) {

		if (n % i == 0) {

			// you've found a factor of n in the range [2, sqRoot]

			// therefore n is not a prime number

			return false;

		}

	}

	// you did not find any factor of n in the range [2, sqRoot]

	// therefore n is a prime number

	return true;

}


void printPrimes(int m) {

	for (int n = 2; n <= m; n++) {

		// check if n is a prime no. or not

		if (isPrime(n)) {

			cout << n << " ";

		}

	}

}

// adv. of using fn

// 1. modularity is helpful in debugging
// 2. readability
// 3. reusability

int main() {

	int m;
	cin >> m;

	printPrimes(m);

	return 0;
}