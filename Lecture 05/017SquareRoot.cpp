#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int sqrt = 0;

	while (sqrt * sqrt <= n) {

		sqrt = sqrt + 1;

	}

	sqrt = sqrt - 1;

	cout << sqrt << endl;


	return 0;
}