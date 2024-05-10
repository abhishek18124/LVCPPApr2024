#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int i = 0;

	for (; i < n; i++) {
		cout << i << " ";
	}

	cout << endl;

	cout << "i = " << i << endl;

	int j = 0;

	while (j < n) {

		cout << j << " ";
		j++;

	}

	cout << endl;

	cout << "j = " << j << endl;

	return 0;
}