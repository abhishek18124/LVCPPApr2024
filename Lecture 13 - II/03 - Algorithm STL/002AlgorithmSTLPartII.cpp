#include<iostream>
#include<algorithm>

using namespace std;

// return true if you want a to be ordered before b

bool comparator(int a, int b) {

	if (a > b) {

		// I want a to be ordered before b since we are sorting in decreasing order

		return true;

	}

	return false;

}


// bool comparator(int a, int b) {

// 	return a > b;

// }


int main() {

	int arr[] = {50, 40, 40, 30, 30, 30, 20, 10, 10};
	int n = sizeof(arr) / sizeof(int);

	// sorting a sequence in the decreasing order

	// 1. using a customer comparator

	sort(arr, arr + n, comparator); // sort(arr, arr + n, &comparator);

	// 2. using greater<T>() function object / functor

	// sort(arr, arr + n, greater<int>());

	// greater<int> fun;

	// sort(arr, arr + n, fun);

	for (int i = 0; i < n; i++) {

		cout << arr[i] << " ";

	}

	cout << endl;

	return 0;
}
