// contraints : n <= 100, k <= 9

#include<iostream>

using namespace std;

// stable counting sort

// time : n.const + k.const + k.const + n.const = O(n+k)
// space: k due to freq[]

int main() {

	int arr[] = {1, 0, 3, 2, 3, 1, 2, 0, 2};
	int n = sizeof(arr) / sizeof(int);

	int k = 3; // denotes the maximum element in the array

	int freq[10] = {0}; // based on constraints

	// n.const

	for (int i = 0; i < n; i++) { // n-steps

		int x = arr[i]; // const
		freq[x]++; // const

	}

	for (int i = 0; i <= k; i++) {
		cout << freq[i] << " ";
	}

	cout << endl;

	for (int i = 1; i < k; i++) { // k-steps
		freq[i] = freq[i] + freq[i - 1]; // const
	}

	for (int i = 0; i <= k; i++) {
		cout << freq[i] << " ";
	}

	cout << endl;

	for (int i = k; i >= 1; i--) { // k-steps
		freq[i] = freq[i - 1]; // const
	}

	freq[0] = 0;

	for (int i = 0; i <= k; i++) {
		cout << freq[i] << " ";
	}

	cout << endl;

	int out[100]; // based on constraints

	for (int i = 0; i < n; i++) { // n-steps

		// int x = arr[i];
		// out[freq[x]] = x;
		// freq[x]++;

		out[freq[arr[i]]++] = arr[i]; // const

	}

	for (int i = 0; i < n; i++) {
		cout << out[i] << " ";
	}

	cout << endl;

	return 0;
}