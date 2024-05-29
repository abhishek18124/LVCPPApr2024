// constraints : n <= 100

#include<iostream>

using namespace std;

// time : O(n)
// space: O(n) due to x[]

int maxSubarraySum(int arr[], int n) {

	int x[100]; // based on constraints

	x[0] = arr[0];
	int maxSoFar = x[0];

	for (int i = 1; i <= n - 1; i++) {
		x[i] = max(x[i - 1] + arr[i], arr[i]);
		maxSoFar = max(maxSoFar, x[i]);
	}

	return maxSoFar;

}


// time : O(n)
// space: O(1)

int maxSubarraySumSpaceOptimised(int arr[], int n) {

	int x = arr[0]; // x represents x[0]
	int maxSoFar = x;

	for (int i = 1; i <= n - 1; i++) {
		x = max(x + arr[i], arr[i]);
		maxSoFar = max(maxSoFar, x);
	}

	return maxSoFar;

}

int main() {

	int arr[] = { -3, 2, -1, 4, -5};
	int n = sizeof(arr) / sizeof(int);

	cout << maxSubarraySum(arr, n) << endl;
	cout << maxSubarraySumSpaceOptimised(arr, n) << endl;

	return 0;
}