// constraints : n <= 100

#include<iostream>
#include<climits>

using namespace std;

// time : n.c + n^2.c ~ O(n^2)
// space: n+1 ~ O(n)

int maximumSubarraySum(int arr[], int n) {

	int csum[101]; // based on problem constraints

	csum[0] = 0;

	for (int i = 1; i <= n; i++) { // n-steps and each step is const
		csum[i] = csum[i - 1] + arr[i - 1];
	}

	int maxSoFar = INT_MIN;

	for (int i = 0; i <= n - 1; i++) { // n^2 steps and each step is const

		for (int j = i; j <= n - 1; j++) {

			int sum = csum[j + 1] - csum[i];
			maxSoFar = max(maxSoFar, sum);

		}

	}

	return maxSoFar;

}

int main() {

	int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = sizeof(arr) / sizeof(int);

	cout <<	maximumSubarraySum(arr, n) << endl;

	return 0;
}