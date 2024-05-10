#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	// iterate over the rows

	int i = 1;

	while (i <= n) {

		// for the ith row, print i nos.

		int j = 1;

		int num = i % 2 == 0 ? 0 : 1;

		// int num;
		// if(i%2 == 0) {
		// 	// i is an even row
		// 	num = 0;
		// } else {
		// 	// is is an odd row
		// 	num = 1;
		// }

		while (j <= i) {
			cout << num << " ";

			// flip the no.

			// if(num == 1) {
			// 	num = 0;
			// } else {
			// 	num = 1;
			// }

			// num = !num;

			num = 1 - num;

			j++;
		}

		cout << endl;

		i++;

	}

	return 0;
}