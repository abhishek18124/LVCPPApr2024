#include<iostream>

using namespace std;

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

	int arr[] = {10, 20, 30, 30, 30, 30, 30, 40, 50, 50};
	int n = sizeof(arr) / sizeof(int);

	int t = 100;

	cout << upperBound(arr, n, t) << endl;

	return 0;
}