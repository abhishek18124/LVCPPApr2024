/*

Suppose there is a ladder with n steps. A person standing at the bottom of the ladder and wants to
reach to its top. Assume the person can take atmost k steps at a time. Then, count the number
of ways, the person can reach the top of the ladder.

Example
	Input : n = 4, k = 3
	Output: 7
	Explanation : [1, 1, 1, 1],
	              [1, 1, 2],
	              [1, 2, 1],
	              [2, 1, 1],
	              [2, 2],
	              [1, 3],
	              [3, 1]

*/
#include<iostream>
#include<vector>

using namespace std;

int f(int n, int k, int i) {

	// base case

	if (i == n) {

		return 1;

	}

	if (i > n) {

		return 0;

	}

	// recursive case

	// find the no. of ways to go from ith step to the nth step

	// decide the next step

	cout << ".";

	int cnt = 0;

	for (int j = 1; j <= k; j++) {

		cnt += f(n, k, i + j);

	}

	return cnt;


}

int main() {

	int n = 4;
	int k = 3;

	cout << f(n, k, 0) << endl;

	return 0;
}