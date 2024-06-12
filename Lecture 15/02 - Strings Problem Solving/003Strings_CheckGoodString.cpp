#include<iostream>
#include<string>

using namespace std;

// bool isGoodString(string str) {

// 	int n = str.size();

// 	for (int i = 0; i < n; i++) {

// 		char ch = str[i];

// 		if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {

// 			// ch is consonant, str is not good

// 			return false;

// 		}

// 	}

// 	// str is good

// 	return true;

// }

bool isGoodString(string str) {

	for (char ch : str) { // range-based loop / for-each loop

		if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {

			// ch is consonant, str is not good

			return false;

		}

	}

	// str is good

	return true;

}

int main() {

	string str = "uoxea";

	isGoodString(str) ? cout << "good" << endl : cout << "not good" << endl;

	return 0;
}