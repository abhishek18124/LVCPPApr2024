#include<iostream>
#include<string>

using namespace std;

int main() {

	string s1 = "abc";

	string s2;
	s2 = s1; // copy assignment operator

	cout << s2 << endl;

	string s3 = "xyz";
	string s4 = s3; // copy constructor

	cout << s4 << endl;

	string s5(s3); // copy constructor
	cout << s5 << endl;

	return 0;
}