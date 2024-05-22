#include<iostream>

using namespace std;

bool isEven(int x) {

	return x % 2 == 0;

}

int main() {

	bool ans = isEven(2);

	cout << ans << endl;

	cout << isEven(3) << endl;

	// a fn call that returns a value can be treated like an expr

	if (isEven(5)) {
		cout << "5 is even" << endl;
	} else {
		cout << "5 is odd" << endl;
	}

	if (isEven(10)) {
		cout << "10 is even" << endl;
	} else {
		cout << "10 is odd" << endl;
	}

	isEven(7) ? cout << "7 is even" << endl : cout << "7 is odd" << endl;

	return 0;
}