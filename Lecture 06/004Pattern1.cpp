#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	// iterate over the rows from 1 to n

	int i = 1;

	while (i <= n) {

		// print i stars for the ith row

		int j = 1;

		while (j <= i) {

			cout << '*';
			j++;

		}

		cout << endl;

		i++;

	}

	cout << endl;

	for (int i = 1; i <= n; i++) {

		// for the ith row, print i stars

		for (int j = 1; j <= i; j++) {

			cout << '*';

		}

		cout << endl;

	}

	return 0;
}