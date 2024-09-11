/*

=============
Edit Distance
=============

Given two strings s1 and s2, return the min. no. of edit operations required to convert
s1 to s2.

You have the following three operations permitted on a word:

	> Insert a character
	> Delete a character
	> Replace a character

The min. no. of edits required to convert s1 to s2 is also known as the edit distance
between s1 & s2.

Examples

Example 1:

	Input: s1 = "food", s2 = "money"
	Output: 4

Example 2:

	Input: s1 = "horse", s2 = "ros"
	Output: 3

	Explanation:
	horse -> rorse (replace 'h' with 'r')
	rorse -> rose (remove 'r')
	rose -> ros (remove 'e')

Example 3:

	Input: s1 = "intention", s2 = "execution"
	Output: 5

	Explanation:
	intention -> inention (remove 't')
	inention -> enention (replace 'i' with 'e')
	enention -> exention (replace 'n' with 'x')
	exention -> exection (replace 'n' with 'c')
	exection -> execution (insert 'u')

*/

#include<iostream>
#include<vector>

using namespace std;

int f(const string& s1, const string& s2, int m, int n, int i, int j) {

	// base case

	if (i == m) {
		// f(m, j) = compute the edit distance b/w s1[m...m-1] i.e. "" and s2[j...n-1]
		return n - j;
	}

	if (j == n) {
		// f(i, n) = compute the edit distance b/w s1[i...m-1] and s2[n...n-1] i.e. ""
		return m - i;
	}

	// recursive case

	// f(i, j) = compute the edit distance b/w s1[i...m-1] and s2[j...n-1]

	// decide the next operation

	// option 1 : do an insertion

	// option 2 : do a deletion

	// option 3 : do a subsitution

	return min(1 + f(s1, s2, m, n, i, j + 1),
	           min(1 + f(s1, s2, m, n, i + 1, j),
	               (int)(s1[i] != s2[j]) + f(s1, s2, m, n, i + 1, j + 1)));

}

// time : O(mn)
// space: mn due to dp[][] + (m+n) due to fn call stk ~ O(mn)

int fTopDown(const string& s1, const string& s2, int m, int n, int i, int j, vector<vector<int>>& dp) {

	// lookup

	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	// base case

	if (i == m) {
		// f(m, j) = compute the edit distance b/w s1[m...m-1] i.e. "" and s2[j...n-1]
		return dp[i][j] = n - j;
	}

	if (j == n) {
		// f(i, n) = compute the edit distance b/w s1[i...m-1] and s2[n...n-1] i.e. ""
		return dp[i][j] = m - i;
	}

	// recursive case

	// f(i, j) = compute the edit distance b/w s1[i...m-1] and s2[j...n-1]

	// decide the next operation

	// option 1 : do an insertion

	// option 2 : do a deletion

	// option 3 : do a subsitution

	return dp[i][j] = min(1 + fTopDown(s1, s2, m, n, i, j + 1, dp),
	                      min(1 + fTopDown(s1, s2, m, n, i + 1, j, dp),
	                          (int)(s1[i] != s2[j]) + fTopDown(s1, s2, m, n, i + 1, j + 1, dp)));

}

// time : O(mn)
// space : O(mn) due to dp[][]
// [hw] to to optimise the space from O(mn) to O(n) using two 1d-vectors and one 1d vector

int fBottomUp(const string& s1, const string& s2, int m, int n) {

	vector<vector<int>> dp(m + 1, vector<int>(n + 1));

	for (int j = 0; j <= n; j++) {
		dp[m][j] = n - j;
	}

	for (int i = 0; i <= m; i++) {
		dp[i][n] = m - i;
	}

	for (int i = m - 1; i >= 0; i--) {

		for (int j = n - 1; j >= 0; j--) {

			// dp[i][j] = // f(i, j) = compute the edit distance b/w s1[i...m-1] and s2[j...n-1]

			// decide the next operation

			// option 1 : do an insertion

			// option 2 : do a deletion

			// option 3 : do a subsitution

			dp[i][j] = min(1 + dp[i][j + 1],
			               min(1 + dp[i + 1][j],
			                   (int)(s1[i] != s2[j]) + dp[i + 1][j + 1]));


		}

	}

	return dp[0][0]; // at the 0,0th index of dp[][] we store f(0, 0)

}

int main() {

	string s1("intention");
	int m = s1.size();

	string s2("execution");
	int n = s2.size();

	cout  << f(s1, s2, m, n, 0, 0) << endl;

	vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

	cout << fTopDown(s1, s2, m, n, 0, 0, dp) << endl;

	cout << fBottomUp(s1, s2, m, n) << endl;

	return 0;
}