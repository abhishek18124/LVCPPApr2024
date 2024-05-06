#include<iostream>

using namespace std;

int main() {

	int a;
	cin >> a;

	int b;
	cin >> b;

	int c;
	cin >> c;

	// if (a > b and a > c) {

	// 	cout << a << endl;

	// } else {

	// 	// either b or c is the largest

	// 	if (b > c) {

	// 		cout << b << endl;

	// 	} else {

	// 		cout << c << endl;

	// 	}

	// 	cout << "you are outside the inner if-else block" << endl;


	// }

	// cout << "you are outside the outer if-else block" << endl;


	if (a > b and a > c) {

		cout << a << endl;

	} else if (b > c) {

		cout << b << endl;

	} else {

		cout << c << endl;

	}

	cout << "you are outside the if-else-if block" << endl;

	return 0;
}