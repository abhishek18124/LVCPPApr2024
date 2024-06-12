#include<iostream>
#include<string>

using namespace std;

int main() {

	string s1;
	cin >> s1;

	string s2;
	cin >> s2;

	if (s1 < s2) {
		cout << s1 << " < " << s2 << endl;
	} else if (s1 > s2) {
		cout << s1 << " > " << s2 << endl;
	} else {
		cout << s1 << " is equal to " << s2 << endl;
	}

	return 0;
}