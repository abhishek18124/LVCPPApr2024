#include<iostream>

using namespace std;

int main() {

	int p;
	cin >> p;

	int r;
	cin >> r;

	int t;
	cin >> t;

	cout << "simple interest = " << p * r * t / 100 << endl;
	cout << "simple interest = " << (p * r * t) / 100 << endl;

	cout << "simple interest = " << (p * r * t * 1.0) / 100 << endl;
	cout << "simple interest = " << (p * r * t) / 100.0 << endl;

	cout << "simple interest = " << (float)p * r * t / 100 << endl;
	cout << "simple interest = " << static_cast<float>(p) * r * t / 100 << endl;

	// float si = (p * r * t) / 100;
	float si = (p * r * t) / 100.0;
	cout << "simple interest = " << si << endl;

	return 0;
}