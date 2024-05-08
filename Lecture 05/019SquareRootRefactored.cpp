#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int p;
	cin >> p;

	double sqrt = 0;

	while (sqrt * sqrt <= n) {

		sqrt = sqrt + 1;

	}

	sqrt = sqrt - 1;


	int i = 1;

	double inc = 0.1;

	while (i <= p) {

		while (sqrt * sqrt <= n) {

			sqrt = sqrt + inc;

		}

		sqrt = sqrt - inc;
		inc = inc / 10;

		i = i + 1;

	}

	cout << sqrt << endl;


	return 0;
}