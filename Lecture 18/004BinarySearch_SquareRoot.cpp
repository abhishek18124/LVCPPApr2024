
/*

	To find the square root of a number 'n', we have to find the
	largest integer 'm' which satisfies the condition m^2 <= n.

*/


#include<iostream>

using namespace std;

// total = logn + p.10 ( n >>> p ) ~ O(logn)

float computeSquareRoot(int n, int p) {

	// square root of 'n' always lies between 0 and n

	int s = 0;
	int e = n;

	float sqr;

	while (s <= e) { // log(n)
		int m = s + (e - s) / 2;
		if (m * m <= n) {
			// 'm' can potentially be integer part the sqrt of 'n'
			sqr = m;
			// since we want to find the largest integer 'm'
			// which satisfies the condition  m^2 <= n  will
			// continue the search towards the right of 'm'
			// i.e. the search space reduces to [m+1, e].
			s = m + 1;
		} else {
			// 'm' cannot be the integer part of sqrt of 'n' therfore
			// continue the search towards the left of 'm' i.e. the
			// search space reduces from [s, e] to [s, m-1].
			e = m - 1;
		}
	}

	float inc = 0.1;

	// p.10 steps

	for (int i = 0; i < p; i++) { // p times
		while (sqr * sqr <= n) { // 10 times
			sqr = sqr + inc;
		}
		sqr = sqr - inc;
		inc = inc / 10;
	}

	return sqr;
}

int main() {

	int n = 30;
	int p = 2;

	cout << computeSquareRoot(n, p) << endl;

	return 0;
}