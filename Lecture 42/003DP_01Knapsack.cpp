/*

Example :
	Input : N = 5, W = 4
			wt[] = {1, 2, 3, 2, 2}
			pr[] = {8, 4, 1, 5, 3}
	Output: 13

*/


#include<iostream>
#include<vector>

using namespace std;

int f(const vector<int>& wt, const vector<int>& pr, int N, int i, int w) {

	// base case

	if (i == N) { // mandatory

		return 0;

	}

	if (w == 0) { // optional

		return 0;

	}

	// recursive case

	// f(i, w) = find the max. profit from items[i...N-1] such that knapsack capacity is w

	if (wt[i] > w) {

		// exlude the ith item from the knapsack
		return f(wt, pr, N, i + 1, w);
	}

	// decide for the ith item

	// option 1 : include the ith item into the knapsack

	// option 2 : exclude the ith item from the knapsack

	return max(pr[i] + f(wt, pr, N, i + 1, w - wt[i]),
	           f(wt, pr, N, i + 1, w));

}

// time :  O(NW)
// space : O(NW) due to dp[][]

int fBottomUp(const vector<int>& wt, const vector<int>& pr, int N, int W) {

	vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0)); // base case cell are automatically filled with zero with this initialisation

	for (int i = N - 1; i >= 0; i--) {
		for (int w = W; w >= 1; w--) {

			// dp[i][w] = f(i, w) = find the max. profit from items[i...N-1] such that knapsack capacity is w

			if (wt[i] > w) {

				dp[i][w] = dp[i + 1][w];

			} else {

				// decide for the ith item

				// option 1 : include it into the knapsack

				// option 2 : exclude it from the knapsack

				dp[i][w] = max(pr[i] + dp[i + 1][w - wt[i]], dp[i + 1][w]);

			}

		}
	}

	return dp[0][W]; // at the (0, W)th index of dp[][] we store f(0, W)

}

// time :  O(NW)
// space : O(W) due to dp[]

int fBottomUpSpaceOptimised(const vector<int>& wt, const vector<int>& pr, int N, int W) {

	vector<int> dp(W + 1, 0); // base case cell are automatically filled with zero with this initialisation

	for (int i = N - 1; i >= 0; i--) {
		for (int w = W; w >= 1; w--) { // mandatory to move right to left when dp[] is 1d

			// dp[i][w] = f(i, w) = find the max. profit from items[i...N-1] such that knapsack capacity is w

			if (wt[i] > w) {

				dp[w] = dp[w];

			} else {

				// decide for the ith item

				// option 1 : include it into the knapsack

				// option 2 : exclude it from the knapsack

				dp[w] = max(pr[i] + dp[w - wt[i]], dp[w]);

			}

		}
	}

	return dp[W]; // dp[W] represents dp[0][W] i.e. f(0, W)

}


int main() {

	int N = 5;
	int W = 4;

	vector<int> wt = {1, 2, 3, 2, 2};
	vector<int> pr = {8, 4, 1, 5, 3};

	cout << f(wt, pr, N, 0, W) << endl;

	cout << fBottomUp(wt, pr, N, W) << endl;

	cout << fBottomUpSpaceOptimised(wt, pr, N, W) << endl;

	return 0;
}