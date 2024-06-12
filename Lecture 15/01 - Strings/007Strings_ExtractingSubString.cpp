#include<iostream>
#include<string>

using namespace std;

int main() {

	string s = "abcdef";

	string ss = s.substr(2, 3);
	cout << ss << endl;

	string sss = s.substr(1);
	cout << sss << endl;

	return 0;
}