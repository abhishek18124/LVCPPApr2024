#include<iostream>

using namespace std;

// time : O(n)
// space : O(1)

int rainwaterOptimised3(int h[], int n) {

	int total = 0; // to store the total water trapped b/w buildings

	int i = 0;
	int j = n - 1;

	int l = 0; // max(h[0] to h[i])
	int r = 0; // max(h[j] to h[n-1])

	while (i <= j) {

		l = max(l, h[i]);
		r = max(r, h[j]);

		if (l < r) {

			// find the water trapped on top of the ith building

			int wi = l - h[i];
			total += wi;
			i++;

		} else { // is l is equal to r, we can compute either wi or wj, it doesn't matter

			// find the water trapped on top of the jth building

			int wj = r - h[j];
			total += wj;
			j--;

		}

	}

	return total;

}

int main() {

	int h[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(h) / sizeof(int);

	cout << rainwaterOptimised3(h, n) << endl;

	return 0;
}