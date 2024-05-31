// n <= 100

#include<iostream>

using namespace std;

// time : 3n.const ~ O(n)
// space: n + n = 2n due l[] and r[] ~ O(n)

int rainwaterOptimised(int h[], int n) {

	int l[100];

	l[0] = h[0];
	for (int i = 1; i <= n - 1; i++) { // ~ n-steps
		l[i] = max(l[i - 1], h[i]); // const
	}

	int r[100];

	r[n - 1] = h[n - 1];
	for (int i = n - 2; i >= 0; i--) { // ~n steps
		r[i] = max(r[i + 1], h[i]); // const
	}

	int total = 0; // to store the total water trapped b/w buildings

	for (int i = 0; i < n; i++) { // n steps

		// find the water trapped on top of the ith building

		int wi = min(l[i], r[i]) - h[i]; // const
		total += wi; // const

	}

	return total;

}


// time : 2n.const ~ O(n)
// space: n due r[] ~ O(n)

int rainwaterOptimised2(int h[], int n) {

	int r[100];

	r[n - 1] = h[n - 1];
	for (int i = n - 2; i >= 0; i--) { // ~n steps
		r[i] = max(r[i + 1], h[i]); // const
	}

	int total = 0; // to store the total water trapped b/w buildings
	int li = 0; // to store max(h[0] to h[i])

	for (int i = 0; i < n; i++) { // n steps

		// find the water trapped on top of the ith building
		li = max(li, h[i]);
		int wi = min(li, r[i]) - h[i]; // const
		total += wi; // const

	}

	return total;

}


int main() {

	int h[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(h) / sizeof(int);

	cout << rainwaterOptimised(h, n) << endl;
	cout << rainwaterOptimised2(h, n) << endl;

	return 0;
}