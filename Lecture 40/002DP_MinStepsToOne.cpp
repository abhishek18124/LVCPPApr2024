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
#include<climits>

using namespace std;

int cnt1 = 0;

int f(int n) {

	cnt1++;

	// base case

	if (n == 1) {

		// f(1) = count min. no. of steps required to reduce 1 to 1

		return 0;

	}

	// recursive case

	// f(n) = count min. no. of steps requried to reduce n to 1

	// decide the next step

	// option 1 : reduce n to n - 1

	int x = f(n - 1);

	// option 2 : reduce n to n / 2 only if n%2 == 0

	int y = INT_MAX;

	if (n % 2 == 0) {
		y = f(n / 2);
	}

	// option 3 : reduce n to n / 3 only if n%3 == 0

	int z = INT_MAX;

	if (n % 3 == 0) {
		z = f(n / 3);
	}

	return 1 + min(x, min(y, z));

}

int cnt2 = 0;

int fTopDown(int n, vector<int>& dp) {

	cnt2++;

	// lookup

	if (dp[n] != -1) {

		// you alredy know min. steps required to reduce n to 1
		return dp[n];

	}

	// base case

	if (n == 1) {

		// f(1) = count min. no. of steps required to reduce 1 to 1

		return dp[n] = 0;

	}

	// recursive case

	// f(n) = count min. no. of steps requried to reduce n to 1

	// decide the next step

	// option 1 : reduce n to n - 1

	int x = fTopDown(n - 1, dp);

	// option 2 : reduce n to n / 2 only if n%2 == 0

	int y = INT_MAX;

	if (n % 2 == 0) {
		y = fTopDown(n / 2, dp);
	}

	// option 3 : reduce n to n / 3 only if n%3 == 0

	int z = INT_MAX;

	if (n % 3 == 0) {
		z = fTopDown(n / 3, dp);
	}

	return dp[n] = 1 + min(x, min(y, z));

}

// time : O(n)
// space: O(n) due to dp[]

int fBottomUp(int n) {

	vector<int> dp(n + 1); // 0th index is not used

	dp[1] = 0; // at the 1st index of dp[] we store f(1)

	for (int i = 2; i <= n; i++) {

		// dp[i] = f(i) = min. steps required to reduce i to 1

		// decide the next step

		// option 1 : reduce i to i - 1

		int x = dp[i - 1];

		// option 2 : reduce i to i / 2

		int y = INT_MAX;
		if (i % 2 == 0) {
			y = dp[i / 2];
		}

		// option 3 : reduce i to i / 3

		int z = INT_MAX;
		if (i % 3 == 0) {
			z = dp[i / 3];
		}

		dp[i] = 1 + min(x, min(y, z)); // dp[i] = 1 + min(dp[i-1], min(dp[i/2], dp[i/3]))

	}

	return dp[n]; // at the nth index of dp[] we store f(n)

}

int main() {

	int n = 20;

	cout << f(n) << endl;

	cout << "cnt1 = " << cnt1 << endl;

	vector<int> dp(n + 1, -1); // 0th index is not used

	cout << fTopDown(n, dp) << endl;

	cout << "cnt2 = " << cnt2 << endl;

	cout << fBottomUp(n) << endl;

	return 0;
}