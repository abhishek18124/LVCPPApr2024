/*

    https://leetcode.com/problems/wildcard-matching/

*/

class Solution {
public:

    bool f(const string& s, const string& p, int m, int n, int i, int j) {

        // base case

        // if(i == m and j == n) return true; // not required, already handled by bases written below

        if (i == m) {

            // check if p[j...n-1] matches s[m...m-1] = ""

            bool flag = true; // assume p[j...n-1] contains only stars

            for (int k = j; k < n; k++) {
                if (p[k] != '*') {
                    flag = false;
                    break;
                }
            }

            return flag;

        }

        if (j == n) { // i != m

            // check if p[n...n-1] = "" matches s[i...m-1]

            return false;

        }

        // recursive case

        // f(i, j) = check if p[j...n-1] matches s[i...m-1]

        if (s[i] == p[j]) {

            // recursively, check if p[j+1...n-1] matches s[i+1...m-1]

            return f(s, p, m, n, i + 1, j + 1);

        } else {

            if (p[j] == '?') {

                // recursively, check if p[j+1...n-1] matches s[i+1...m-1]

                return f(s, p, m, n, i + 1, j + 1);

            } else if (p[j] == '*') {

                // option 1 : don't use *

                // option 2 : use *

                return f(s, p, m, n, i, j + 1) or f(s, p, m, n, i + 1, j);

            } else {

                // p[j] is not a wildcard character

                return false;

            }

        }


    }


    bool fRefactored(const string& s, const string& p, int m, int n, int i, int j) {

        // base case

        if (i == m) {

            // check if p[j...n-1] matches s[m...m-1] = ""

            bool flag = true; // assume p[j...n-1] contains only stars

            for (int k = j; k < n; k++) {
                if (p[k] != '*') {
                    flag = false;
                    break;
                }
            }

            return flag;

        }

        if (j == n) { // i != m

            // check if p[n...n-1] = "" matches s[i...m-1]

            return false;

        }

        // recursive case

        // f(i, j) = check if p[j...n-1] matches s[i...m-1]

        if (s[i] == p[j] || p[j] == '?') {

            // recursively, check if p[j+1...n-1] matches s[i+1...m-1]

            return f(s, p, m, n, i + 1, j + 1);

        } else if (p[j] == '*') {

            // option 1 : don't use *

            // option 2 : use *

            return f(s, p, m, n, i, j + 1) or f(s, p, m, n, i + 1, j);

        } else {

            // p[j] is not a wildcard character

            return false;

        }


    }


    bool fTopDown(const string& s, const string& p, int m, int n, int i, int j, vector<vector<int>>& dp) {

        // lookup

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // base case

        if (i == m) {

            // check if p[j...n-1] matches s[m...m-1] = ""

            bool flag = true; // assume p[j...n-1] contains only stars

            for (int k = j; k < n; k++) {
                if (p[k] != '*') {
                    flag = false;
                    break;
                }
            }

            return dp[i][j] = flag;

        }

        if (j == n) { // i != m

            // check if p[n...n-1] = "" matches s[i...m-1]

            return dp[i][j] = false;

        }

        // recursive case

        // f(i, j) = check if p[j...n-1] matches s[i...m-1]

        if (s[i] == p[j] || p[j] == '?') {

            // recursively, check if p[j+1...n-1] matches s[i+1...m-1]

            return dp[i][j] = fTopDown(s, p, m, n, i + 1, j + 1, dp);

        } else if (p[j] == '*') {

            // option 1 : don't use *

            // option 2 : use *

            return dp[i][j] = fTopDown(s, p, m, n, i, j + 1, dp) or fTopDown(s, p, m, n, i + 1, j, dp);

        } else {

            // p[j] is not a wildcard character

            return dp[i][j] = false;

        }


    }

    // time : O(mn)
    // space: O(mn)
    // [HW] : optimise space from O(mn) to O(n)
    // Try space optimisating using only 1 1d-vector

    bool fBottomUp(const string& s, const string& p, int m, int n) {

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));

        for (int j = 0; j <= n - 1; j++) {

            // check if p[j...n-1] matches s[m...m-1] = ""

            bool flag = true; // assume p[j...n-1] contains only stars

            for (int k = j; k < n; k++) {
                if (p[k] != '*') {
                    flag = false;
                    break;
                }
            }

            dp[m][j] = flag;

        }

        for (int i = 0; i <= m - 1; i++) {

            // check if p[n...n-1] = "" matches s[i...m-1]

            dp[i][n] = false;

        }

        dp[m][n] = true; // dp[m][n] = f(m, n) = check if p[n..n-1] = "" matches s[m..m-1] = ""

        for (int i = m - 1; i >= 0; i--) {

            for (int j = n - 1; j >= 0; j--) {

                // dp[i][j] = f(i, j) = check if p[j...n-1] matches s[i...m-1]

                if (s[i] == p[j] || p[j] == '?') {

                    // recursively, check if p[j+1...n-1] matches s[i+1...m-1]

                    dp[i][j] = dp[i + 1][j + 1];

                } else if (p[j] == '*') {

                    // option 1 : don't use *

                    // option 2 : use *

                    dp[i][j] = dp[i][j + 1] or dp[i + 1][j];

                } else {

                    // p[j] is not a wildcard character

                    dp[i][j] = false;

                }


            }

        }

        return dp[0][0]; // at the 0,0th index of dp[][] we store f(0, 0)

    }

    bool isMatch(string s, string p) {

        int m = s.size();
        int n = p.size();

        // return f(s, p, m, n, 0, 0);

        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        // return fTopDown(s, p, m, n, 0, 0, dp);

        return fBottomUp(s, p, m, n);

    }
};