#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int arr[] = {50, 40, 40, 30, 30, 30, 20, 10, 10};
	int n = sizeof(arr) / sizeof(int);

	// 1. sorting a sequence using built-in sort() in O(nlogn) // introsort used

	sort(arr, arr + n); // [0, n) [begin, end) by default sorting is done in increasing order

	for (int i = 0; i < n; i++) {

		cout << arr[i] << " ";

	}

	cout << endl;

	// 2. reversing a sequence using the built-in reverse()

	reverse(arr, arr + n); // [begin, end)

	for (int i = 0; i < n; i++) {

		cout << arr[i] << " ";

	}

	cout << endl;

	// 3. reversing a sequence in-range using the built-in reverse()

	reverse(arr + 2, arr + 7); // reverses arr[2, 7)

	for (int i = 0; i < n; i++) {

		cout << arr[i] << " " ;

	}

	cout << endl;


	return 0;
}
