#include<iostream>
#include<string>

using namespace std;

int main() {

	string str = "hello";

	for (int i = 0; i < str.size(); i++) {
		cout << "str[" << i << "] = " << str[i] << endl;
	}

	cout << endl;

	for (int i = 0; str[i] != '\0'; i++) {
		cout << "str[" << i << "] = " << str[i] << endl;
	}

	return 0;
}