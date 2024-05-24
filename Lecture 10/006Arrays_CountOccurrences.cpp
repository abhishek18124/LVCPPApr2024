#include<iostream>

using namespace std;

int lowerBound(int arr[], int n, int t) {

	int s = 0; // lower bound of the search space
	int e = n - 1; // upper bound of the search space

	int ans = -1; // to store the idx of the 1st occurrence of the t in arr[]

	while (s <= e) {

		int m = s + (e - s) / 2;

		if (arr[m] == t) {

			// t found at index m
			ans = m;

			// move towards the left of the midPoint because there may be more occurrences of t in arr[]
			e = m - 1;

		} else if (t > arr[m]) {

			// search for t to the right of the midPoint i.e.
			// search space reduces from [s, e] to [m+1, e]
			s = m + 1;

		} else {

			// t < arr[m]

			// search for the t to the left of the midPoint i.e.
			// search space reduces from [s, e] to [s, m-1]

			e = m - 1;
		}

	}

	return ans;

}

int upperBound(int arr[], int n, int t) {

	int s = 0; // lower bound of the search space
	int e = n - 1; // upper bound of the search space

	int ans = -1; // to store the idx of the last occurrence of the t in arr[]

	while (s <= e) {

		int m = s + (e - s) / 2;

		if (arr[m] == t) {

			// t found at index m
			ans = m;

			// move towards the right of the midPoint because there may be more occurrences of t in arr[]
			s = m + 1;

		} else if (t > arr[m]) {

			// search for t to the right of the midPoint i.e.
			// search space reduces from [s, e] to [m+1, e]
			s = m + 1;

		} else {

			// t < arr[m]

			// search for the t to the left of the midPoint i.e.
			// search space reduces from [s, e] to [s, m-1]

			e = m - 1;
		}

	}

	return ans;

}


int main() {

	int arr[] = {10, 10, 10, 20, 30, 30, 30, 30, 30, 40, 50, 50};
	int n = sizeof(arr) / sizeof(int);

	int t = 50;

	int fo = lowerBound(arr, n, t);

	if (fo == -1) {

		// t is not present in arr[]

		cout << 0 << endl;

	} else {

		int lo = upperBound(arr, n, t);

		cout << lo - fo + 1 << endl;

	}


	return 0;
}