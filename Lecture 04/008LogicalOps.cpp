#include<iostream>

using namespace std;

int main() {

	cout << "true && true : " << (true && true) << endl;
	cout << "true && false : " << (true && false) << endl;
	cout << "false && true : " << (false and true) << endl;
	cout << "false && false : " << (false and false) << endl;

	cout << endl;

	cout << "true || true : " << (true || true) << endl;
	cout << "true || false : " << (true || false) << endl;
	cout << "false or true : " << (false or true) << endl;
	cout << "false or false : " << (false or false) << endl;

	cout << endl;

	cout << "!true : " << (!true) << endl;
	cout << "!false : " << (!false) << endl;

	int x = 10;
	int y = 0;

	cout << (x and y) << endl; // 10 and 0 => true and false => false => 0
	cout << (x or y) << endl; // 10 or 0 => true or false => true => 1

	return 0;
}