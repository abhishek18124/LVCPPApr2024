#include<iostream>

using namespace std;

int f(string str, int n) {

	// base case

	if (n == 0) { // str == "" // str.empty()
		// convert empty string into an integer
		return 0;
	}

	// if(n == 1) {
	// 	// convert a string of length 1 into an integer
	// 	return str[0]-'0';
	// }

	// recursive case

	// convert str[0...n-1] into an integer

	// 1. ask your friend to convert str[0...n-2] into an integer

	string subString = str.substr(0, n - 1);
	int integerFromMyFriend = f(subString, n - 1);
	return integerFromMyFriend * 10 + (str[n - 1] - '0');

}

int main() {

	string str;
	cin >> str;

	int n = str.size();

	cout << f(str, n) << endl;

	return 0;
}