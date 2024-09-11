/*

Given two strings s1 and s2, return the length of their longest common subsequence.
If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters
(can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Example :

	Input : s1 = "ATGC", s2 = "AGCT"
	Output: 3
	Explanation : "AGC" is the LCS between s1 and s2

	Input : s1 = "AGGTAB", s2 = "GXTXAYB"
	Output: 4
	Explanation : “GTAB” is the LCS between s1 and s2

*/

#include<iostream>
#include<vector>

using namespace std;

int f(const string& s1, const string& s2, int m, int n, int i, int j) {

	// base case

	if (i == m || j == n) {

		// f(m, j) = find the length of the lcs b/w s1[m...m-1] i.e. "" and s2[j...n-1]

		// f(i, n) = find the length of the lcs b/w s1[i...m-1] and s2[n...n-1] i.e. ""

		return 0;
	}

	// recursive case

	// f(i, j) = find the length of the lcs b/w s1[i...m-1] and s2[j...n-1]

	if (s1[i] == s2[j]) {

		// recursively, find the length of the lcs b/w s1[i+1...m-1] and s2[j+1...n-1]

		return 1 + f(s1, s2, m, n, i + 1, j + 1);

	}

	// s1[i] != s2[j]

	// recursively, find the length of the lcs b/w s1[i+1...m-1] and s2[j...n-1]

	// recursively, find the length of the lcs b/w s1[i...m-1] and s2[j+1...n-1]

	return max(f(s1, s2, m, n, i + 1, j),
	           f(s1, s2, m, n, i, j + 1));


}

int fTopDown(const string& s1, const string& s2, int m, int n, int i, int j, vector<vector<int>>& dp) {

	// lookup

	if (dp[i][j] != -1) {

		// you've already solve f(i, j)

		return dp[i][j];

	}

	// base case

	if (i == m || j == n) {

		// f(m, j) = find the length of the lcs b/w s1[m...m-1] i.e. "" and s2[j...n-1]

		// f(i, n) = find the length of the lcs b/w s1[i...m-1] and s2[n...n-1] i.e. ""

		return dp[i][j] = 0;
	}

	// recursive case

	// f(i, j) = find the length of the lcs b/w s1[i...m-1] and s2[j...n-1]

	if (s1[i] == s2[j]) {

		// recursively, find the length of the lcs b/w s1[i+1...m-1] and s2[j+1...n-1]

		return dp[i][j] = 1 + fTopDown(s1, s2, m, n, i + 1, j + 1, dp);

	}

	// s1[i] != s2[j]

	// recursively, find the length of the lcs b/w s1[i+1...m-1] and s2[j...n-1]

	// recursively, find the length of the lcs b/w s1[i...m-1] and s2[j+1...n-1]

	return dp[i][j] = max(fTopDown(s1, s2, m, n, i + 1, j, dp),
	                      fTopDown(s1, s2, m, n, i, j + 1, dp));


}

// time : O(mn)
// space: O(mn) due to dp[][]

int fBottomUp(const string& s1, const string& s2, int m, int n) {

	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // mth row and nth column are set to zero since they were the base cases

	for (int i = m - 1; i >= 0; i--) {

		for (int j = n - 1; j >= 0; j--) {

			// dp[i][j] = f(i, j) = find the length of the lcs b/w s1[i...m-1] and s2[j...n-1]

			if (s1[i] == s2[j]) {

				dp[i][j] = 1 + dp[i + 1][j + 1];

			} else {

				dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);

			}

		}

	}

	// for (int i = 0; i <= m; i++) {
	// 	for (int j = 0; j <= n; j++) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;

	int x = 0;
	int y = 0;

	string ans = "";

	while (x != m || y != n) {
		if (s1[x] == s2[y]) { // value of dp[x][y] is dependent on dp[x+1][y+1]
			ans += s1[x]; // s2[y]
			x++;
			y++;
		} else if (dp[x][y] == dp[x][y + 1]) { // value of dp[x][y] is dependent on dp[x][y+1]
			y++;
		} else { // value of dp[x][y] is dependent on dp[x+1][y]
			x++;
		}
	}

	cout << ans << endl;

	return dp[0][0]; // at the 0,0th index of dp[][] we store f(0, 0)

}

// time : O(mn)
// space: O(n) using two 1d vectors

int fBottomUpSpaceOptimised(const string& s1, const string& s2, int m, int n) {

	vector<int> nextRow(n + 1, 0); // initially, nextRow represents the mth row of dp[][]

	for (int i = m - 1; i >= 0; i--) {

		vector<int> currRow(n + 1);
		currRow[n] = 0;

		for (int j = n - 1; j >= 0; j--) {

			// dp[i][j] = f(i, j) = find the length of the lcs b/w s1[i...m-1] and s2[j...n-1]

			if (s1[i] == s2[j]) {

				currRow[j] = 1 + nextRow[j + 1];

			} else {

				currRow[j] = max(nextRow[j], currRow[j + 1]);

			}

		}

		// nextRow = currRow; // curRow is copied into nextRow (expensive) (internally copy semantics of c++ are used)

		nextRow = move(currRow); // move semantics (cheap) / nextRow is stealing elements of currRow

	}

	return nextRow[0]; // nextRow[0] stores dp[0][0] i.e. result of f(0, 0)

}

// time : O(mn)
// space: O(n) using only a single 1d vector

int fBottomUpMoreSpaceOptimised(const string& s1, const string& s2, int m, int n) {

	vector<int> dp(n + 1, 0); // initially dp[] represents the mth row

	for (int i = m - 1; i >= 0; i--) {

		int temp1 = 0;

		for (int j = n - 1; j >= 0; j--) {

			int temp2 = dp[j]; // temp2 store dp[i+1][j]

			// dp[i][j] = f(i, j) = find the length of the lcs b/w s1[i...m-1] and s2[j...n-1]

			if (s1[i] == s2[j]) {

				dp[j] = 1 + temp1;

			} else {

				dp[j] = max(dp[j], dp[j + 1]);

			}

			temp1 = temp2;

		}

	}

	return dp[0]; // at the 0th of dp[] we store f(0, 0)

}


int main() {

	string s1("ABCDA");
	string s2("BACDA");

	int m = s1.size();
	int n = s2.size();

	cout << f(s1, s2, m, n, 0, 0) << endl;

	vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

	cout << fTopDown(s1, s2, m, n, 0, 0, dp) << endl;

	cout << fBottomUp(s1, s2, m, n) << endl;

	cout << fBottomUpSpaceOptimised(s1, s2, m, n) << endl;

	cout << fBottomUpMoreSpaceOptimised(s1, s2, m, n) << endl;

	return 0;
}