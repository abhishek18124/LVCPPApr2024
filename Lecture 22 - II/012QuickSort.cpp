// constraints : n <= 100

#include<iostream>

using namespace std;

int partition(int arr[], int s, int e) {

	int j = s;
	int i = s - 1; // j-1

	int pivot = arr[e];

	// while (j < e) {

	// 	if (arr[j] < pivot) {

	// 		// arr[j] should be in the leftParition

	// 		i++;
	// 		swap(arr[i], arr[j]);
	// 		j++;

	// 	} else {

	// 		// arr[j] should be in the rightParition
	// 		j++;

	// 	}

	// }

	while (j < e) {

		if (arr[j] < pivot) {

			// arr[j] should be in the leftParition

			i++;
			swap(arr[i], arr[j]);

		}

		j++;

	}

	swap(arr[e], arr[i + 1]);
	return i + 1;

}

void quickSort(int arr[], int s, int e) {

	// base case

	if (s > e) { // mandatory base case
		return;
	}

	if (s == e) { // optional base case
		return;
	}

	// recursive case

	// sort arr[s...e] using quickSort algorithm

	// 1. partition the arr[s...e] around the pivot

	int pidx = partition(arr, s, e);

	// 2. recursively sort the left and right partition i.e. arr[s...pidx-1] and arr[pidx+1...e]

	quickSort(arr, s, pidx - 1);
	quickSort(arr, pidx + 1, e);

}

int main() {

	int arr[] = {60, 50, 20, 10, 40, 30};
	int n = sizeof(arr) / sizeof(int);

	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}