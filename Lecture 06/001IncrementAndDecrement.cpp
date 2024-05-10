#include<iostream>

using namespace std;

int main() {

	int x = 0;

	x++; // or ++x

	cout << "x : " << x << endl;

	int y = 1;

	y--; // or --y

	cout << "y : " << y << endl;

	int a = 10;

	int b = a++;

	cout << "a = " << a << " b = " << b << endl; // 11 10

	int c = 20;

	int d = ++c;

	cout << "c = " << c << " d = " << d << endl; // 21 21

	int e = 30;

	cout << e++ << endl;
	cout << e << endl;

	int f = 40;

	cout << ++f << endl;
	cout << f << endl;

	return 0;
}