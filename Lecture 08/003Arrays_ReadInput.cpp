// 1 <= n <= 100

#include<iostream>

using namespace std;

int main() {

	int arr[100]; // based on constraints

	int n;
	cin >> n;

	// 1. read values into the array

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// 2. print the values in the array

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	// 3. print the values in the array in reverse

	for (int i = n - 1; i >= 0; i--) {
		cout << arr[i] << " ";
	}

	cout << endl;

	int B[5];

	B[0] = 1000;
	B[1] = 2000;
	B[2] = 3000;
	B[3] = 4000;
	B[4] = 5000;

	for (int i = 0; i < 5; i++) {
		cout << B[i] << " ";
	}

	cout << endl;

	return 0;
}