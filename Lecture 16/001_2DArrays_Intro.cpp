/*

	Constraints

	0 < m, n <= 10

	here, m denotes the no. of rows in the given 2D array
	      n denotes the no. of cols in the given 2D array

*/

#include<iostream>

using namespace std;

int main() {

	int arr[10][10];

	int m;
	cin >> m; // 3

	int n;
	cin >> n; // 4

	// read mxn values into the 2D array

	// cin >> arr[0][0];
	// cin >> arr[0][1];
	// cin >> arr[0][2];
	// cin >> arr[0][3];

	// cin >> arr[1][0];
	// cin >> arr[1][1];
	// cin >> arr[1][2];
	// cin >> arr[1][3];

	// cin >> arr[2][0];
	// cin >> arr[2][1];
	// cin >> arr[2][2];
	// cin >> arr[2][3];

	for (int i = 0; i <= m - 1; i++) {

		// read values in the ith row

		for (int j = 0; j <= n - 1; j++) {

			cin >> arr[i][j];

		}

	}

	// print mxn values of the 2D array

	for (int i = 0; i <= m - 1; i++) {

		// print the ith row

		for (int j = 0; j <= n - 1; j++) {

			cout << arr[i][j] << " ";

		}

		cout << endl;

	}

	return 0;
}


