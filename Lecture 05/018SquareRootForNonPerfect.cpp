#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	double sqrt = 0;

	while (sqrt * sqrt <= n) {

		sqrt = sqrt + 1;

	}

	sqrt = sqrt - 1;

	while (sqrt * sqrt <= n) {

		sqrt = sqrt + 0.1;

	}

	sqrt = sqrt - 0.1;

	while (sqrt * sqrt <= n) {

		sqrt = sqrt + 0.01;

	}

	sqrt = sqrt - 0.01;

	while (sqrt * sqrt <= n) {

		sqrt = sqrt + 0.001;

	}

	sqrt = sqrt - 0.001;

	cout << sqrt << endl;


	return 0;
}