#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int f(const vector<int>& arr, int N, int k, int i) {

	// base case

	if (i == N) {
		return 0;
	}

	// recursive case

	// f(i) = find the max. sum from partitioning arr[i...N-1] such that size of each subarray is <= K

	// decide the next cut

	int maxSumij = INT_MIN;
	int maxSoFar = INT_MIN;

	for (int j = i; j <= i + k - 1 and j <= N - 1; j++) {

		// make a cut at index j
		maxSumij = max(maxSumij, arr[j]);
		maxSoFar = max(maxSoFar, (j - i + 1) * maxSumij + f(arr, N, k, j + 1));

	}

	return maxSoFar;

}


int fTopDown(const vector<int>& arr, int N, int k, int i, vector<int>& dp) {

	// lookup
	if (dp[i] != -1) {
		return dp[i];
	}

	// base case

	if (i == N) {
		return dp[i] = 0;
	}

	// recursive case

	// f(i) = find the max. sum from partitioning arr[i...N-1] such that size of each subarray is <= K

	// decide the next cut

	int maxSumij = INT_MIN;
	int maxSoFar = INT_MIN;

	for (int j = i; j <= i + k - 1 and j <= N - 1; j++) {

		// make a cut at index j
		maxSumij = max(maxSumij, arr[j]);
		maxSoFar = max(maxSoFar, (j - i + 1) * maxSumij + fTopDown(arr, N, k, j + 1, dp));

	}

	return dp[i] = maxSoFar;

}

// time : O(nk)
// space: O(n) due to dp[]

int fBottomUp(const vector<int>& arr, int N, int k) {

	vector<int> dp(N + 1);
	dp[N] = 0; // at the Nth index of dp[] we store f(N)

	for (int i = N - 1; i >= 0; i--) {

		// dp[i] = f(i) = find the max. sum from partitioning arr[i...N-1] such that size of each subarray is <= K

		// decide the next cut

		int maxSumij = INT_MIN;
		int maxSoFar = INT_MIN;

		for (int j = i; j <= i + k - 1 and j <= N - 1; j++) {

			// make a cut at index j
			maxSumij = max(maxSumij, arr[j]);
			maxSoFar = max(maxSoFar, (j - i + 1) * maxSumij + dp[j + 1]);

		}

		dp[i] = maxSoFar;

	}

	return dp[0]; // at the 0th index of dp[] we store f(0)

}

int maxSumAfterPartitioning(vector<int>& arr, int K) {

	int N = arr.size();

	// return f(arr, N, K, 0);

	// vector<int> dp(N + 1, -1);
	// return fTopDown(arr, N, K, 0, dp);

	return fBottomUp(arr, N, K);

}

int main() {

	vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
	int K = 3;

	cout << maxSumAfterPartitioning(arr, K) << endl;

	return 0;
}