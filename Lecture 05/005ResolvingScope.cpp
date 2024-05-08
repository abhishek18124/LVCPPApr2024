#include<iostream>

using namespace std;

int x = 100; // global variable

int main() {

	cout << x << endl; // 100

	int x = 10; // local variable

	cout << x << endl; // 10

	{

		int x = 30; // local variable
		int y = 20; // local variable

		cout << x << " " << y << endl; // 30 20

		{

			int y = 50;
			int z = 40;

			cout << x << " " << y << " " << z << endl; // 30 50 40

		}

		cout << x << " " << y << endl;  // 30 20

	}

	// cout << x << " " << y << endl;

	return 0;
}