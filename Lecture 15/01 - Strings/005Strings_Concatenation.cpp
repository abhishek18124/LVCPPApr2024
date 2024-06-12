#include<iostream>
#include<string>

using namespace std;

int main() {

	string s1 = "abc";
	string s2 = "def";

	// s1.append(s2);
	s1 = s1 + s2;

	cout << s1 << endl;
	cout << s2 << endl;

	string s = "hell";

	cout << s << endl;
	s.push_back('o');
	cout << s << endl;
	s.pop_back();
	cout << s << endl;
	s.pop_back();
	cout << s << endl;

	cout << s.front() << " " << s[0] << endl;
	cout << s.back() << " " << s[s.size() - 1] << endl;

	string t = "worl";

	// t.push_back('d');

	char ch = 'd';

	t = t + string(1, ch); // use this if t = t + ch doesn't work
	// t += ch;

	cout << t << endl;

	return 0;
}