#include<iostream>

using namespace std;

int main() {

	// int a = 10;
	// int b = 5;

	int a, b;
	cin >> a >> b;

	cout << "a+b = " << a + b << endl; // 57
	cout << "a-b = " << a - b << endl; // 43
	cout << "a*b = " << a*b << endl; // 350

	cout << "a/b = " << a / b << endl; // exp 7.14 act 7 why ? int / int => int

	cout << "a/b = " << (float)a / b << endl; // C-style explicit type-casting
	cout << "a/b = " << a / (float)b << endl; // C-style explicit type-casting

	cout << "a/b = " << float(a) / b << endl; // C-style explicit type-casting
	cout << "a/b = " << a / float(b) << endl; // C-style explicit type-casting

	cout << "a/b = " << static_cast<float>(a) / b << endl; // C++-style explicit type-casting
	cout << "a/b = " << a / static_cast<float>(b) << endl; // C++-style explicit type-casting


	cout << "a%b = " << a % b << endl; // 1

	cout << "3+5*4 = " << 3 + 5 * 4 << endl;
	cout << "8-4/2 = " << 8 - 4 / 2 << endl;
	cout << "(3+5)*4 = " << (3 + 5) * 4 << endl;
	cout << "(8-4)/2 = " << (8 - 4) / 2 << endl;
	cout << "100/10*10 = " << 100 / 10 * 10 << endl;
	cout << "5-2+3 = " << 5 - 2 + 3 << endl;

	return 0;
}