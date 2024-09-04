/*

Suppose there is a ladder with n steps.  A person standing at the
bottom of the  ladder and  wants to reach to its top. Assume the
person can take a jump of size 1 to k at a time. Then, count the
number of ways, the person can reach the top of the ladder.

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

int f(int n, int k) {

	// base case

	if (n == 0) {

		// f(0, k) = count the no. of ways to reach the 0th step from the 0th step

		return 1;

	}

	// recursive case

	// f(n, k) = count the no. of ways to reach the nth step from the 0th step

	int cnt = 0;

	for (int j = 1; j <= k; j++) {

		// can you reach the nth step from the n-jth step ?

		if (n - j >= 0) { // you can reach the nth step from the n-jth step,

			// now ask your friend to count the no. of ways to reach the n-jth step from the 0th step

			cnt += f(n - j, k);

		}

	}

	return cnt;

}

int main() {

	int n = 4;
	int k = 3;

	cout << f(n, k) << endl;

	return 0;
}