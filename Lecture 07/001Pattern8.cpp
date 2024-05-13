#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int i = 1;
	while (i <= n) {

		// print n-i+1 characters in the inc. order starting with A

		int j = 1;
		char ch = 'A';

		while (j <= n - i + 1) {
			cout << ch;
			ch++; // ch = ch + 1 e.g. ch = 'A' => ch = ch + 1 => A + 1 => 65 + 1 = 66
			j++;
		}

		cout << endl;
		i++;

	}

	return 0;
}