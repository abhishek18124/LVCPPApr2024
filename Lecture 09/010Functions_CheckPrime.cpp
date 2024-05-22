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

int main() {

	int n;
	cin >> n;

	isPrime(n) ? cout << "prime" << endl : cout << "not prime" << endl;

	return 0;
}