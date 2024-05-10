#include<iostream>

using namespace std;

int main() {

	int cnt = 0; // to track the no. of characters
	char ch;

	while (true) {

		// cin >> ch; // it will ignore whitespaces
		ch = cin.get(); // it will not ignore whitespaces

		if (ch == '$') {
			break;
		}

		cnt++;

	}

	cout << "cnt = " << cnt << endl;

	return 0;
}