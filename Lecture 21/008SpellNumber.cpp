#include<iostream>

using namespace std;

string spellingMap[] = { "zero", "one", "two", "three",
                         "four", "five", "six", "seven",
                         "eight", "nine"
                       };


void f(int n) {

	// base case

	if (n == 0) {

		return;

	}

	// recursive case

	// print the spelling of n

	// 1. ask your friend to print the spelling of n/10

	f(n / 10);

	// 2. print the spelling of the digit at the one's place i.e rightmost digit

	int d = n % 10;

	cout << spellingMap[d] << " ";

}

int main() {

	int n;
	cin >> n;

	f(n);

	return 0;
}