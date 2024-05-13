#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int cnt = 0; // to track the no. of set bits in 'n'

	// iterate over the set bits of n to count the no. of set bits

	while (n > 0) {
		cnt++;
		// clear the rightmost bit of n
		int mask = n - 1;
		n = n & mask;
	}

	cout << cnt << endl;

	return 0;
}