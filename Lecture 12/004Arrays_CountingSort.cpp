// contraints : n <= 100, k <= 9

#include<iostream>

using namespace std;

// non-stable counting sort

// total = n.c + n.c = 2n.c ~ O(n)
// space = k+1 ~ O(k) due to freq[]

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
		cout << "freq(" << i << ") = " << freq[i] << endl;
	}

	// n.const

	for (int i = 0; i <= k; i++) {

		int y = freq[i];

		// print 'i' y times

		for (int j = 1; j <= y; j++) {
			cout << i << " "; // const
		}

	}

	cout << endl;

	return 0;
}