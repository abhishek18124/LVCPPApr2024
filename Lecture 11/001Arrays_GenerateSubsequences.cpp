#include<iostream>

using namespace std;

void generateSubsequences(int arr[], int n) {

	for (int num = 0; num < (1 << n); num++) {

		cout << num << " : ";

		for (int k = 0; k < n; k++) {

			if ((num >> k) & 1) {

				cout << arr[k] << " ";

			}

		}

		cout << endl;

	}

}

int main() {

	int arr[] = {10, 20, 30};
	int n = sizeof(arr) / sizeof(int);

	generateSubsequences(arr, n);

	return 0;
}
