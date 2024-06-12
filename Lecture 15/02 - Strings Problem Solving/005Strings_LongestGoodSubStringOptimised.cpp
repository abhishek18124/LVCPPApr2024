#include<iostream>
#include<string>

using namespace std;

int main() {

	string str = "cbaeicdeiou";

	int maxSoFar = 0; // to track the length of the longest good substring
	int cnt = 0;

	for (char ch : str) { // O(n)

		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {

			// ch is vowel

			cnt++;
			maxSoFar = max(maxSoFar, cnt);

		} else {

			// ch is a consonant
			cnt = 0;

		}

	}

	cout << maxSoFar << endl;

	return 0;
}