#include<iostream>

using namespace std;

int main() {

	int arr[5];

	cout << sizeof(arr) << 'B' << endl;

	int n = sizeof(arr) / sizeof(int);

	cout << n << endl;

	char str[10];

	cout << sizeof(str) << 'B' << endl;

	double drr[20];

	cout << sizeof(drr) << 'B' << endl;

	float frr[5];

	cout << sizeof(frr) << 'B' << endl;

	return 0;
}