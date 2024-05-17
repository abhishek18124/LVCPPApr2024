// 1 <= n <= 100
#include<iostream>

using namespace std;

int main() {

	// int arr[] = {10, 20, 30, 40, 50, 60, 70};
	// int n = sizeof(arr) / sizeof(int);

	// int k = 3;

	int arr[100];

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int k;
	cin >> k;

	k = k % n;

	// 1. reverse arr[0...n-1]

	int i = 0;
	int j = n - 1;

	while (i < j) {
		swap(arr[i], arr[j]);
		i++;
		j--;
	}

	// 2. reverse arr[0...k-1]

	i = 0;
	j = k - 1;

	while (i < j) {
		swap(arr[i], arr[j]);
		i++;
		j--;
	}

	// 3. reverse arr[k...n-1]

	i = k;
	j = n - 1;

	while (i < j) {
		swap(arr[i], arr[j]);
		i++;
		j--;
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}