#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 10, 20};
	int n = sizeof(arr) / sizeof(int);

	int t = 100;
	// int cnt = 0; // to store no. of times 't' is found in arr[]
	bool flag = false; // assume t is not present in arr[]

	for (int i = 0; i < n; i++) {

		if (arr[i] == t) {

			// cnt++;
			flag = true;
			cout << i << " ";

		}

	}

	// if (cnt == 0) {
	// 	cout << t << " not found" << endl;
	// }

	if (flag == false) {
		cout << t << " not found" << endl;
	}

	return 0;
}