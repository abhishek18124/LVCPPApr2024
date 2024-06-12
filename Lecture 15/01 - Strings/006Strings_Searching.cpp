#include<iostream>
#include<string>

using namespace std;

int main() {

	string s = "abcdcdcdef";
	string t = "cd";

	cout << s.find(t) << endl; // returns the starting index of the 1st occurrence of t in s
	cout << s.rfind(t) << endl; // returns the starting index of the last occurrence of t in s

	string u = "zz";
	cout << s.find(u) << endl;
	cout << string::npos << endl;

	if (s.find(u) != string::npos) {
		// u is present in s
	} else {
		// u is not present in s
	}

	return 0;
}