/*

Given a number n, count the minimum steps to reduce n to 1
such that at each step you may

	reduce n to n/2 if n is divisible by 2
	or reduce n to n/3 if n is divisible by 3
	or reduce n to n-1 by decrementing n by 1

Example :
	Input : n = 10
	Output : 3

	Input : 6
	Output : 2

*/

#include<iostream>
#include<vector>

using namespace std;

int f(int n) {

	// base case

	if (n == 1) {

		// f(1) = count min. no. of steps required to reduce 1 to 1

		return 0;

	}

	// recursive case

	// f(n) = count min. no. of steps requried to reduce n to 1

	// todo ...

}

int main() {

	int n = 10;

	cout << f(n) << endl;

	return 0;
}