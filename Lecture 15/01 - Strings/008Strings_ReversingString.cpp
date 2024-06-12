#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {

	string s = "abcdef";

	// reverse(s.begin(), s.end());
	reverse(s.begin() + 1, s.begin() + 4); // reverses s[1:4)
	// reverse(s.begin() + 1, s.end() - 2); // reverses s[1:4)

	cout << s << endl;

	return 0;
}