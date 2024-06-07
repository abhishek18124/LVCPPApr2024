#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int arr[] = {50, 40, 40, 30, 30, 30, 20, 10, 10};
	int n = sizeof(arr) / sizeof(int);

	int key = 30;

	// 1. searching for a key in a sequence using find()

	auto it = find(arr, arr + n, key);

	if (it == arr + n) {

		cout << key << " not found" << endl;

	} else {

		cout << key << " found at address " << it << endl;
		cout << key << " found at index " << (it - arr) << endl;

	}

	// 2. counting the occurrences of a key in a sequence using count()

	key = 10;

	cout << count(arr, arr + n, key) << endl;

	return 0;
}
