#include<iostream>

using namespace std;

// time : O(n^2) since we spend linear time on each building
// space: O(1)

int rainwater(int h[], int n) {

	int total = 0; // to store the total water trapped b/w buildings

	for (int i = 0; i < n; i++) {

		// find the water trapped on top of the ith building

		// li = max(h[0] to h[i])

		int li = h[i];
		for (int j = i - 1; j >= 0; j--) {
			li = max(li, h[j]); // const
		}

		// ri = max(h[i] to h[n-1])

		int ri = h[i];
		for (int j = i + 1; j <= n - 1; j++) {
			ri = max(ri, h[j]); // const
		}

		int wi = min(li, ri) - h[i];
		total += wi;

	}

	return total;

}

int main() {

	int h[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(h) / sizeof(int);

	cout << rainwater(h, n) << endl;

	return 0;
}