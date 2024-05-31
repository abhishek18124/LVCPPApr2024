// contraints : m <= 10, n <= 10

#include<iostream>

using namespace std;

// time : O(m+n)
// space: O(m+n) due crr[] if counting output space otherwise O(1)

void merge(int arr[], int m, int brr[], int n) {

	int crr[20]; // based on constraints

	int i = 0;
	int j = 0;
	int k = 0;

	while (i <= m - 1 and j <= n - 1) {

		if (arr[i] < brr[j]) {
			crr[k] = arr[i];
			i++;
			k++;
		} else {
			crr[k] = brr[j];
			j++;
			k++;
		}

	}

	while (i <= m - 1) {

		crr[k] = arr[i];
		i++;
		k++;

	}

	while (j <= n - 1) {

		crr[k] = brr[j];
		j++;
		k++;

	}

	for (int l = 0; l <= m + n - 1; l++) {
		cout << crr[l] << " ";
	}

	cout << endl;


}

int main() {

	int arr[] = {10, 30, 50, 70, 80};
	int brr[] = {20, 40, 60, 90, 100, 110};

	int m = sizeof(arr) / sizeof(int);
	int n = sizeof(brr) / sizeof(int);

	merge(arr, m, brr, n);

	return 0;
}

